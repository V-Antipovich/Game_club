#include "ParserConsoleException.h"

ParserConsoleException::ParserConsoleException(const std::string &what): std::runtime_error(what) {}
