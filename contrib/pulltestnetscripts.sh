#!/bin/bash

echo bearsd-testnet: getting deployment scripts from external source

wget -qO- $SCRIPTURL/master/$LAUNCHENV/$APP/testnetinit.sh > /usr/local/bin/testnetinit.sh
wget -qO- $SCRIPTURL/master/$LAUNCHENV/$APP/testnet.config.ini > /etc/bearsd/testnet.config.ini
wget -qO- $SCRIPTURL/master/$LAUNCHENV/$APP/fastgen.config.ini > /etc/bearsd/fastgen.config.ini
chmod +x /usr/local/bin/testnetinit.sh

echo bearsd-testnet: launching testnetinit script

/usr/local/bin/testnetinit.sh
