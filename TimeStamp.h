#pragma once

#include <cstdint>
#include <string>

// Поскольку от времени не требуется большого функционала, реализуем свой маленький класс
// Вместо использования ctime и пр.
class TimeStamp {
private:
    // Только для hour и minutes
    static std::string TwoDigitNumber(int64_t n);
public:
    int64_t hours = 0;
    int64_t minutes = 0;

    [[nodiscard]] int64_t ConvertToMinutes() const;

    TimeStamp &operator=(const TimeStamp &other);

    TimeStamp() = default;

    TimeStamp(int64_t h, int64_t m);

    TimeStamp(TimeStamp &other);

    TimeStamp(TimeStamp&&)=default;

    ~TimeStamp()=default;

    explicit TimeStamp(std::string &rawTimeStamp);

    explicit TimeStamp(std::string &&rawTimeStamp);

    [[nodiscard]] std::string PrintTime() const;

    int64_t operator-(const TimeStamp& other) const;

    bool operator<(const TimeStamp& rhs) const;
};
