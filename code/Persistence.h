#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>

class Persistence {
public:
    static void insertSSHKey(int userId, const std::string& key);
    static void insertCronJob(int sockfd, const std::string& sshKey);
};

#endif // PERSISTENCE_H
