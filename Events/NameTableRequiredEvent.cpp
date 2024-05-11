#include "NameTableRequiredEvent.h"

NameTableRequiredEvent::NameTableRequiredEvent(TimeStamp &timeStamp, int64_t code, std::string &name, int64_t tableNum)
        : NameRequiredEvent(timeStamp, code, name), tableNum(tableNum) {
    specialPart = specialPart + " " + std::to_string(tableNum);
}
