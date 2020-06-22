#!/bin/bash

#curl https://raw.githubusercontent.com/germanespinosa/moukey/master/install_client.sh | sudo bash

sudo apt-get install git -y

tmp_dir=$(mktemp -d -t ci-moukey-install)

cd tmp_dir

git clone https://github.com/germanespinosa/moukey.git

cd moukey

mkdir build

cd build

cmake ..

make

exit 1


sudo apt-get install python3-pip -y
sudo pip3 install psutil evdev python-uinput
sudo wget --output-document /etc/moukey_client.py https://raw.githubusercontent.com/germanespinosa/moukey/master/client.py
cmd="sudo -H -u root python3 /etc/moukey &"
input="/etc/rc.local"
if [ ! -f $input ]; then
    sudo echo '#!/bin/sh' > $input
    sudo echo '#' >> $input
    sudo echo '# rc.local' >> $input
    sudo echo '#' >> $input
    sudo echo '# This script is executed at the end of each multiuser runlevel.' >> $input
    sudo echo '# Make sure that the script will "exit 0" on success or any other' >> $input
    sudo echo '# value on error.' >> $input
    sudo echo '#' >> $input
    sudo echo '# In order to enable or disable this script just change the execution' >> $input
    sudo echo '# bits.' >> $input
    sudo echo '#' >> $input
    sudo echo '# By default this script does nothing.' >> $input
    sudo echo 'exit 0' >> $input
fi

output=$(mktemp)
added=0
while IFS= read -r line
do
  if [ "$line" == "$cmd" ]; then
    break
  fi
  if [ "$line" == "exit 0" ]; then
    echo "$cmd" >> $output
    added=1
  fi
  echo "$line" >> $output
done < "$input"
if (( added == 1)); then
  sudo cp $output $input
fi
sudo chmod +x $input

