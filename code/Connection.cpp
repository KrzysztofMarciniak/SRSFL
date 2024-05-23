#include "Connection.h"
#include <unistd.h>
#include <iostream>

Connection::Connection(const std::string& ip, int port) : ip(ip), port(port) {}

Connection::~Connection() {}

bool Connection::establish() {
    return socket.connectToServer(ip, port);
}

void Connection::sendData(const std::string& data) {
    send(socket.getSocketFd(), data.c_str(), data.length(), 0);
}

int Connection::getSocketFd() const {
    return socket.getSocketFd(); 
}
