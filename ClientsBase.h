#pragma once

#include <map>
#include <unordered_map>
#include "Client.h"

class ClientsBase {
    private:
        int64_t nextID = 0;
        std::unordered_map<std::string, int64_t> IdByName;
        std::map<int64_t, Client> base;
    public:
        int64_t AddIfNew(std::string &name);
        std::string GetName(int64_t ID);

        bool IsPresent(int64_t id);

        bool IsSitting(int64_t id);

        bool IsWaiting(int64_t id);

        void ClientSits(int64_t id, int64_t tableId);

        void ClientWaits(int64_t id, int64_t pos);

        void ClientLeaves(int64_t id);

        int64_t GetTableNumber(int64_t ID);

        ClientsBase()=default;
};
