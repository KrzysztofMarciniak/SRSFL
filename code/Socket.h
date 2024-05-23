
#ifndef SOCKET_H
#define SOCKET_H

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Socket {
public:
    Socket();
    ~Socket();

    bool connectToServer(const std::string& ip, int port);
    int getSocketFd() const;

private:
    int sockfd;
};

#endif 
