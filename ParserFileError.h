#pragma once

#include <stdexcept>
#include <string>

class ParserFileError: public std::runtime_error {
    public:
        explicit ParserFileError(const std::string &what="");
};
