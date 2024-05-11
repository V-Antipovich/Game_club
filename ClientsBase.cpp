#include "ClientsBase.h"

void ClientsBase::AddIfNew(std::string &name) {
    if (auto it = IdByName.find(name); it == IdByName.end()) {
        ++nextID;
        IdByName[name] = nextID;
        Client newClient(nextID, name);
    }
}

std::string ClientsBase::GetName(int64_t ID) {
    std::string name;
    if (auto it = base.find(ID); it != base.end()) {
        name = base[ID].name;
    }
    return name;
//    return base[ID].name;
}