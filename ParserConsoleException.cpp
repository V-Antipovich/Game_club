//
// Created by vitalii on 5/9/24.
//

#include "ParserConsoleException.h"
ParserConsoleException::ParserConsoleException(const std::string &what): std::runtime_error(what) {}
