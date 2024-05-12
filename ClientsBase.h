#pragma once

#include <unordered_map>
#include <map>
//#include "ParserFile.h"
#include "Client.h"
// TODO: class of Client, enum class of statuses. Множество свободных столов тоже нужно
class ClientsBase {
    private:
        int64_t nextID = 0;
        std::unordered_map<std::string, int64_t> IdByName;
        std::map<int64_t, Client> base;
    public:
        int64_t AddIfNew(std::string &name);
        std::string GetName(int64_t ID);
//        int64_t GetID(std::string &name);
        bool IsPresent(int64_t id);
        bool IsSitting(int64_t id);
        bool IsWaiting(int64_t id);
        void ClientSits(int64_t id, int64_t tableId);
        int64_t GetTableNumber(int64_t ID);
        ClientsBase()=default;
};
