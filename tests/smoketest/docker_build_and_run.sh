#!/bin/bash
#params:
# - ref voilkd location
# - tested voilkd location
# - ref blockchain folder location
# - tested blockchain folder location
# - path to directory, where non-empty logs should be generated
# - stop replay at block
# - number of jobs (optional)
# - --dont-copy-config (optional), if passed config.init files are not copied from test directories
#
# WARNING: use absolute paths instead of relative!
#
# sudo ./docker_build_and_run.sh ~/voilknetwork/voilk/build/Release/programs/voilkd ~/voilknetwork/voilk/build/Release/programs/voilkd ~/voilknetwork/voilkd_data/voilknet ~/voilknetwork/voilkd_data/voilknet ~/voilknetwork/logs 5000000 12

if [ $# -lt 6 -o $# -gt 8 ]
then
   echo "Usage: reference_voilkd_location tested_voilkd_location ref_blockchain_folder_location tested_blockchain_folder_location"
   echo "       logs_dir stop_replay_at_block [jobs [--dont-copy-config]"
   echo "Example: ~/voilknetwork/ref_voilkd ~/voilknetwork/voilk/build/Release/programs/voilkd ~/voilknetwork/voilknet ~/voilknetwork/testnet"
   echo "         ~/voilknetwork/logs 5000000 12"
   echo "         if <jobs> not passed, <nproc> will be used."
   exit -1
fi

echo $*

JOBS=0

if [ $# -eq 7 ]
then
   JOBS=$7
fi

docker build -t smoketest ../ -f Dockerfile
[ $? -ne 0 ] && echo docker build FAILED && exit -1

docker system prune -f

if [ -e $5 ]; then
   rm -rf $5/*
else
   mkdir -p $5
fi

docker run -v $1:/reference -v $2:/tested -v $3:/ref_blockchain -v $4:/tested_blockchain -v $5:/logs_dir -v /run:/run \
   -e STOP_REPLAY_AT_BLOCK=$6 -e JOBS=$JOBS -e COPY_CONFIG=$8 -p 6990:6990 -p 6991:6991 smoketest:latest
