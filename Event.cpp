#include "Event.h"

Event::Event(TimeStamp &timeStamp, int64_t ID, std::string &name, int64_t tableNum) : timeStamp(timeStamp), ID(ID),
                                                                                      clientName(name),
                                                                                      tableNum(tableNum) {
    specialPart = clientName + " " + std::to_string(tableNum);
}

Event::Event(TimeStamp &timeStamp, int64_t ID, std::string &str, bool isError) : timeStamp(timeStamp), ID(ID),
                                                                                 specialPart(str) {
    if (isError) {
        error = str;
    } else {
        clientName = str;
    }
}

std::string Event::to_str() const {
    std::string printString = timeStamp.PrintTime() + " " + std::to_string(ID) + " " + specialPart;
    return printString;
}

