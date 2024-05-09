#pragma once
#include <ctime>
#include <string>
class BaseEvent {
    protected:
        std::tm timeStamp;
        std::string clientName;

    public:
        BaseEvent();
        virtual void Act();
        virtual void Print();
        virtual ~BaseEvent() = default;
};
