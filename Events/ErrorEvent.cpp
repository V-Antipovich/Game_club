#include "ErrorEvent.h"

ErrorEvent::ErrorEvent(std::tm &timeStamp, int64_t code, std::string &error) : BaseEvent(timeStamp, code),
                                                                               errorName(error) {}

void ErrorEvent::Act() {
    // TODO: implement!!
    std::cout<<"ErrorEvent playing\n";
}