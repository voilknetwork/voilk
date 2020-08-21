#!/bin/bash

function echo(){ builtin echo $(basename $0 .sh): "$@"; }
pushd () { command pushd "$@" > /dev/null; }
popd () { command popd "$@" > /dev/null; }

if [ $# -ne 5 ]
then
   echo Usage: node_kind voilkd_path node_options work_path port
   echo Example: reference ~/voilknetwork/voilk/build/programs/voilkd/voilkd --webserver-http-endpoint=127.0.0.1:6990 ~/working 6990
   exit -1
fi

function check_pid_port {
   echo Checking that voilkd with pid $1 listens at $2 port.

   NETSTAT_CMD="netstat -tlpn 2> /dev/null"
   STAGE1=$(eval $NETSTAT_CMD)
   # echo STAGE1: $STAGE1
   STAGE2=$(echo $STAGE1 | grep -o ":$2 [^ ]* LISTEN $1/voilkd")
   ATTEMPT=0

   while [[ -z $STAGE2 ]] && [ $ATTEMPT -lt 3 ]; do
      sleep 3
      STAGE1=$(eval $NETSTAT_CMD)
      STAGE2=$(echo $STAGE1 | grep -o ":$2 [^ ]* LISTEN $1/voilkd")
      ((ATTEMPT++))
   done

   if [[ -z $STAGE2 ]]; then
      echo FATAL: Could not find voilkd with pid $1 listening at port $2 using $NETSTAT_CMD command.
      echo FATAL: Most probably another voilkd instance is running and listens at the port.
      kill -s SIGINT $1
      return 1
   else
      return 0
   fi
}

PID=-1
NAME=$1 
VOILKD_PATH=$2
NODE_OPTIONS=$3
WORK_PATH=$4
TEST_PORT=$5

function cleanup {
   if [ $PID -gt 0 ]
   then
      sleep 0.1 && kill -s SIGINT $PID &
      wait $PID
      [ $? -eq 0 ] && echo ERROR: $VOILKD_PATH exited with error
   fi
   exit -1
}

trap cleanup SIGINT SIGPIPE

echo Running $NAME voilkd to listen
$VOILKD_PATH $NODE_OPTIONS -d $WORK_PATH & PID=$!

if [ $PID -le 0 ]
then
   echo FATAL: cannot run $VOILKD_PATH
   exit -1
fi

if check_pid_port $PID $TEST_PORT; then
   VOILKD_NODE_PID=$PID
   echo NODE: $VOILKD_NODE_PID
fi
