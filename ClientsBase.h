#pragma once

#include <unordered_map>
#include <map>
//#include "ParserFile.h"
#include "Client.h"
// TODO: class of Client, enum class of statuses. Множество свободных столов тоже нужно
class ClientsBase {
    private:
        int64_t nextID = 0;
        std::map<std::string, int64_t> IdByName;
        std::map<int64_t, Client> base;
    public:
        void AddIfNew(std::string &name);
        std::string GetName(int64_t ID);
        ClientsBase()=default;
};
