#!/bin/bash
#curl https://raw.githubusercontent.com/germanespinosa/moukey/master/install_client.sh | sudo bash

sudo apt-get install cmake git -y
tmp_dir=$(mktemp -d -t ci-moukey-install)
cd $tmp_dir
git clone https://github.com/germanespinosa/moukey.git
cd moukey
mkdir build
cd build
cmake ..
make install