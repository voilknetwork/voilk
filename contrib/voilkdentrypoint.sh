#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start voilkd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/voilkd
  cp /usr/local/bin/voilk-sv-run.sh /etc/service/voilkd/run
  chmod +x /etc/service/voilkd/run
  runsv /etc/service/voilkd
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasvoilkd.sh
fi
