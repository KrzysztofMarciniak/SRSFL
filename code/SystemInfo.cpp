#include "SystemInfo.h"
#include <unistd.h>
#include <sys/utsname.h>
#include <iostream>
#include <sstream>

SystemInfo::SystemInfo(Connection& conn) : conn(conn) {}

void SystemInfo::sendSystemInfo() {
    std::string hostname = getHostname();
    std::string unameInfo = getUname();

    conn.sendData("Hostname: " + hostname + "\n");
    conn.sendData("System Information: " + unameInfo + "\n");
}

std::string SystemInfo::getHostname() {
    char buffer[1024];
    gethostname(buffer, sizeof(buffer));
    return std::string(buffer);
}

std::string SystemInfo::getUname() {
    struct utsname buffer;
    uname(&buffer);

    std::stringstream ss;
    ss << buffer.sysname << " " << buffer.nodename << " " << buffer.release << " " << buffer.version << " " << buffer.machine;
    return ss.str();
}
