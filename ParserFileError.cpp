#include "ParserFileError.h"

ParserFileError::ParserFileError(const std::string &what): std::runtime_error(what) {}
