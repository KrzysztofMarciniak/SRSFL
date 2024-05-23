#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include "Connection.h"

class SystemInfo {
public:
    SystemInfo(Connection& conn);
    void sendSystemInfo();

private:
    Connection& conn;
    std::string getHostname();
    std::string getUname();
};

#endif 
