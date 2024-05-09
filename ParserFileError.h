//
// Created by vitalii on 5/9/24.
//

#pragma once
#include <string>
#include <stdexcept>

class ParserFileError: public std::runtime_error {
    public:
        explicit ParserFileError(const std::string &what="");
};
