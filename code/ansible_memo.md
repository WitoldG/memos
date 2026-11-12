How to manually launch a playbook on preprod


# VPN to preprod, connect to deployer to retrieve sha
ex:  sha256:a64db342a990e4b147cdebd50ed7f4c73b3d143a871b99597837cb36420f7b83

# ssh supervisor, split en deux



# left:
$ cd /exotec/deployer/data/[MY_SHA_WITH_:_ESCAPED]/metadata/ansible/astar/install/
$ sudo vim inventory
>[ASTAR]
>172.17.0.8

$ sudo cp main.yml main.yml.bak
$ sudo vim main.yml
# comment all the unneeded steps


$ cd /exotec/deployer/data/[MY_SHA_WITH_:_ESCAPED]/metadata/ansible/astar/install/roles/keycloak
sudo vim FILE_I_WANT_TO_CHANGE

# right:
sudo docker exec -it deployer_backend_1 bash
cd /exotec/deployer/data/[MY_SHA_WITH_:_ESCAPED]/metadata/ansible/astar/install/
ANSIBLE_HOST_KEY_CHECKING=False
ansible-playbook -v main.yml -i inventory


###################
Python version not correct
> force version with ansible_python_interpreter
diff --git a/projects/ProjectBuilder/ansible/playbook/configure_keycloak.yml b/projects/ProjectBuilder/ansible/playbook/configure_keycloak.yml
index 18ec7f014d1..54baed2df39 100644
--- a/projects/ProjectBuilder/ansible/playbook/configure_keycloak.yml
+++ b/projects/ProjectBuilder/ansible/playbook/configure_keycloak.yml
@@ -1,9 +1,9 @@
 ---
 - hosts: localhost
-  connection: local
-
   vars:
     keycloak_configuration_path: "../../../../tools/build-skypodsystem/metadata/ansible/astar/install/roles/keycloak"
+    ansible_connection: local
+    ansible_python_interpreter: "/home/ccocquempot/.pyenv/versions/3.11.11/envs/projectbuilder/bin/python"

