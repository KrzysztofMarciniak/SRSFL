#!/bin/bash

attacker_ip=$(docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' attacker_container)

echo "$attacker_ip" > ip.txt

docker exec attacker_container cat /root/.ssh/id_rsa.pub > ssh-key.txt

echo "Contents of id_rsa.pub inserted into ssh-key.txt"
echo "Attacker's IP address inserted into ip.txt"
