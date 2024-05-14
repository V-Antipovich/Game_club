#pragma once

#include <stdexcept>
#include <string>

class ParserConsoleException: public std::runtime_error {
    public:
        explicit ParserConsoleException(const std::string& what="");
};
