#include "NameRequiredEvent.h"

NameRequiredEvent::NameRequiredEvent(TimeStamp &timeStamp, int64_t code, std::string &name) : BaseEvent(timeStamp,
                                                                                                        code) {
    clientName = name;
    specialPart = name;
}
