# SRSFL
Simple Reverse Shell for Linux
### Setup:
```console
docker-compose up -d
```
### Instruction:

(`cd code && ./setup.sh`) to insert attacker ssh key and ip.

(`make clean && make`) to compile the reverse shell binary.

(`docker exec -it attacker_container /bin/bash`) shell on attack container.

(`nc -lvp 1234`) - listener.

(`docker exec -it victim_container /bin/bash`) shell on victim container, to turn on reverse shell binary.
