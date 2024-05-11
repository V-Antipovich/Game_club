#include "EventsFactory.h"

BaseEvent *
CreateClientCameEvent(std::tm &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra) {
    return new ClientCameEvent(timeStamp, code, extra["name"]);
}

BaseEvent *CreateClientSatEvent(std::tm &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra) {
    return new ClientSatEvent(timeStamp, code, extra["name"], stoll(extra["tableNum"]));
}

BaseEvent *
CreateClientWaitingEvent(std::tm &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra) {
    return new ClientWaitingEvent(timeStamp, code, extra["name"]);
}

BaseEvent *
CreateClientGoneEvent(std::tm &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra) {
    return new ClientGoneEvent(timeStamp, code, extra["name"]);
}

BaseEvent *CreateErrorEvent(std::tm &timeStamp, int64_t code, std::unordered_map<std::string, std::string> &extra) {
    return new ErrorEvent(timeStamp, code, extra["errorName"]);
}

std::unordered_map<int64_t, std::function<BaseEvent *(std::tm &, int64_t,
                                                      std::unordered_map<std::string, std::string> &)>>
CreateEventsMap() {
    std::unordered_map<int64_t, std::function<BaseEvent *(std::tm &, int64_t,
                                                          std::unordered_map<std::string, std::string> &)>> events_map;
    events_map[1] = CreateClientCameEvent;
    events_map[2] = CreateClientSatEvent;
    events_map[3] = CreateClientWaitingEvent;
    events_map[4] = CreateClientGoneEvent;
    events_map[13] = CreateErrorEvent;

    return events_map;
}