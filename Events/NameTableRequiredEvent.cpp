#include "NameTableRequiredEvent.h"

NameTableRequiredEvent::NameTableRequiredEvent(std::tm &timeStamp, int64_t code, std::string &name, int64_t tableNum)
        : NameRequiredEvent(timeStamp, code, name), tableNum(tableNum) {
}
