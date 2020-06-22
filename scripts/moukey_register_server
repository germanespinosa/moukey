#!/bin/bash

#curl -s https://raw.githubusercontent.com/germanespinosa/moukey/master/install_server.sh | sudo bash
sudo su

echo "Installing Moukey Server 0.1.2020 by German Espinosa "
echo "---------------------------------------------------- "

sudo apt-get install python3-pip -y > /dev/null
sudo pip3 install psutil evdev python-uinput asyncio > /dev/null
sudo wget --quiet --output-document /etc/moukey_server.py https://raw.githubusercontent.com/germanespinosa/moukey/master/moukey_server.py > /dev/null
sudo wget --quiet --output-document /etc/moukey_connection.py https://raw.githubusercontent.com/germanespinosa/moukey/master/moukey_connection.py > /dev/null
sudo wget --quiet --output-document /etc/moukey_device_pool.py https://raw.githubusercontent.com/germanespinosa/moukey/master/moukey_device_pool.py > /dev/null
cmd="sudo -H -u pi python3 /etc/moukey_server.py -d &"
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

echo "Moukey installed successfully. Reboot needed"
