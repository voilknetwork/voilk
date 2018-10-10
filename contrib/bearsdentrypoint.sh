#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start bearsd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/bearsd
  cp /usr/local/bin/bears-sv-run.sh /etc/service/bearsd/run
  chmod +x /etc/service/bearsd/run
  runsv /etc/service/bearsd
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasbearsd.sh
fi
