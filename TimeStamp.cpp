#include "TimeStamp.h"

std::string TimeStamp::TwoDigitNumber(int64_t n) {
    std::string str_n = std::to_string(n);
    if (str_n.size() == 1) {
        str_n.insert(0, "0");
    }
    return str_n;
}

int64_t TimeStamp::ConvertToMinutes() const {
    return hours*60 + minutes;
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

int64_t TimeStamp::operator-(const TimeStamp &other) const{
    return this->ConvertToMinutes() - other.ConvertToMinutes();
}

bool TimeStamp::operator<(const TimeStamp &rhs) const {
    return hours<rhs.hours || (hours == rhs.hours && minutes < rhs.minutes);
}

bool TimeStamp::operator>(const TimeStamp &rhs) const {
    return hours>rhs.hours || (hours == rhs.hours && minutes > rhs.minutes);
}
