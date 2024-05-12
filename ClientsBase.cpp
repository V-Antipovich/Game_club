#include "ClientsBase.h"

int64_t ClientsBase::AddIfNew(std::string &name) {
    if (auto it = IdByName.find(name); it == IdByName.end()) {
        ++nextID;
        IdByName[name] = nextID;
//        Client newClient(nextID, name);
        base[nextID] = Client(nextID, name);
    }
    return IdByName[name];
}

std::string ClientsBase::GetName(int64_t ID) {
    std::string name;
    if (auto it = base.find(ID); it != base.end()) {
        name = base[ID].name;
    }
    return name;
//    return base[ID].name;
}

bool ClientsBase::IsPresent(int64_t id) {
    return base[id].is_present;
}

bool ClientsBase::IsSitting(int64_t id) {
    return base[id].currentTableNum > 0;
}

bool ClientsBase::IsWaiting(int64_t id) {
    return base[id].currentQueuePlace > 0;
}

int64_t ClientsBase::GetTableNumber(int64_t ID) {
    return base[ID].currentTableNum;
}

void ClientsBase::ClientSits(int64_t id, int64_t tableId) {
    base[id].is_present = true;
    base[id].currentQueuePlace = -1;
    base[id].currentTableNum = tableId;
}
