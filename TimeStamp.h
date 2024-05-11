#pragma once

#include <cstdint>
#include <string>

// Поскольку от времени не требуется большого функционала, реализуем свой маленький класс
// Вместо использования ctime и пр.
class TimeStamp {
    // TODO: сюда переместить форматированный вывод (инкапсулируем)
    // TODO: сюда же арифметику с подсчетом минус часов (timedelta) (всё через перевод в минуты)
private:
    // Только для hour и minutes
    static std::string TwoDigitNumber(int64_t n);

public:
    int64_t hours = 0;
    int64_t minutes = 0;

    TimeStamp &operator=(const TimeStamp &other);

    TimeStamp() = default;

    TimeStamp(int64_t h, int64_t m);

    TimeStamp(TimeStamp &other);

    explicit TimeStamp(std::string &rawTimeStamp);

    [[nodiscard]] std::string PrintTime() const;
};
