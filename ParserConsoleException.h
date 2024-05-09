//
// Created by vitalii on 5/9/24.
//
#pragma once
#include <string>
#include <stdexcept>

class ParserConsoleException: public std::runtime_error {
    public:
        explicit ParserConsoleException(const std::string& what="");
};
