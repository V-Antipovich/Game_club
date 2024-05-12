#include "ErrorEvent.h"

ErrorEvent::ErrorEvent(TimeStamp &timeStamp, int64_t code, std::string &error) : BaseEvent(timeStamp, code),
                                                                               errorName(error) {
    specialPart = errorName;
}

void ErrorEvent::Act(GamerClubEnv& env, std::queue<BaseEvent*>& outputQueue) {
    // TODO: implement!!
    std::cout<<"ErrorEvent playing\n";
}

BaseEvent *CreateErrorEvent(TimeStamp &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra) {
    return new ErrorEvent(timeStamp, code, extra["errorName"]);
}
