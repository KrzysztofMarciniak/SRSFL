#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>

class Persistence {
public:
    static void insertSSHKey(int userId, const std::string& key);
};

#endif // PERSISTENCE_H
