//
// Created by vitalii on 5/9/24.
//

#include "ParserFileError.h"
ParserFileError::ParserFileError(const std::string &what): std::runtime_error(what) {}
