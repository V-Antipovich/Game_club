#include "ErrorEvent.h"

ErrorEvent::ErrorEvent(TimeStamp &timeStamp, int64_t code, std::string &error) : BaseEvent(timeStamp, code),
                                                                               errorName(error) {}

void ErrorEvent::Act(GamerClubEnv& env, std::queue<BaseEvent*>& outputQueue) {
    // TODO: implement!!
    std::cout<<"ErrorEvent playing\n";
}