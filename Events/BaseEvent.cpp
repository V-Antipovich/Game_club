#include "BaseEvent.h"

BaseEvent::BaseEvent(TimeStamp &timeStamp, int64_t code) : timeStamp(timeStamp), code(code) {}

std::string BaseEvent::GetPrintString() const {
    std::string printString = timeStamp.PrintTime() + " " + std::to_string(code) + " " + specialPart;
    return printString;
}
