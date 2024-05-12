#pragma once

#include <cstdint>
#include <string>

// Имена могут быть очень большими, поэтому выгоднее хранить в других структурах IDшники клиентов
class Client {
public:
    int64_t ID = 0;
    std::string name;
    bool is_present = false;
    int64_t currentTableNum = -1;
    int64_t currentQueuePlace = -1;

    Client() = default;

    Client(int64_t ID, std::string &name);
};
