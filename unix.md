# Manage services systemctl
sudo systemctl start pcsd.service
sudo systemctl stop pcsd.service
sudo systemctl reload pcsd.service
sudo systemctl restart pcsd.service
sudo systemctl is-active pcsd.service


# Pyenv
## General
`pyenv install --list | grep smth` See available versions
`pyrnv update` Access to newer versions
`pyenv install 3.7.2` Install a given version
`pyenv version` List of installed versions
Versions located in folder `~/.pyenv/versions/`
Remove version -> Remove the associated folder
`pyenv global 3.6.8` Tell which version is used globally
`pyenv local 3.11.5` Specify python version in the current folder
`pyenv shell 3.11.5` Open shell on given version
`pip install -r requirements.txt`
## Virtualenv
Pyenv virtualenv: https://wiki.exotec.com/exotec/index.php/Python#Use_pyenv_virtualenv
`pyenv virtualenv <python_version> <environment_name>` Create a new virtualenv
`pyenv local <environment_name>` Activate the virtualenv
`pyenv uninstall <environment_name>` Delete env

# Change default gcc and g++ versions 
sudo update-alternatives --config gcc

# Find
folder `find . -type d -name 'httpdocs'`

# Grep
`grep "text" path/to/file`
recursive `grep -r 'text' .`