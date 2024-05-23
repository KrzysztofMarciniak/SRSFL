#include "Socket.h"
#include <unistd.h>
#include <cstring>
#include <iostream>

Socket::Socket() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed\n";
    }
}

Socket::~Socket() {
    close(sockfd);
}

bool Socket::connectToServer(const std::string& ip, int port) {
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip.c_str(), &servaddr.sin_addr) <= 0) {
        std::cerr << "Invalid address/Address not supported\n";
        return false;
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Connection failed\n";
        return false;
    }

    return true;
}

int Socket::getSocketFd() const {
    return sockfd;
}
