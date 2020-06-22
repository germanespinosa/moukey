#!/bin/bash
#curl https://raw.githubusercontent.com/germanespinosa/moukey/master/scripts/install_core.sh | sudo bash

sudo apt-get install cmake git libevdev-dev -y
tmp_dir=$(mktemp -d -t ci-XXXXXXXXXX)
cd $tmp_dir
git clone https://github.com/germanespinosa/moukey.git
cd moukey
mkdir build
cd build
cmake ..
make install