#include "TimeStamp.h"

std::string TimeStamp::TwoDigitNumber(int64_t n) {
    std::string str_n = std::to_string(n);
    if (str_n.size() == 1) {
        str_n.insert(0, "0");
    }
    return str_n;
}

TimeStamp &TimeStamp::operator=(const TimeStamp &other) {
    if (this == &other) {
        return *this;
    }
    hours = other.hours;
    minutes = other.minutes;
    return *this;
}

TimeStamp::TimeStamp(int64_t h, int64_t m) : hours(h), minutes(m) {}

TimeStamp::TimeStamp(TimeStamp &other) {
    *this = other;
}

TimeStamp::TimeStamp(std::string &rawTimeStamp) {
    // TODO: валидируем и бросаем ошибку в случае чего
    hours = stoll(rawTimeStamp.substr(0, 2));
    minutes = stoll(rawTimeStamp.substr(3, 2));

}

std::string TimeStamp::PrintTime() const {
    std::string output = TwoDigitNumber(hours) + ":" + TwoDigitNumber(minutes);
    return output;
}
