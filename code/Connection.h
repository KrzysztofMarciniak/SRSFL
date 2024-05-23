#ifndef CONNECTION_H
#define CONNECTION_H

#include "Socket.h"
#include <string>

class Connection {
public:
    Connection(const std::string& ip, int port);
    ~Connection();

    bool establish();
    void sendData(const std::string& data);
    int getSocketFd() const; 

private:
    Socket socket;
    std::string ip;
    int port;
};

#endif 
