#include <gtest/gtest.h>
#include "../ParserConsole.h"
char** CastVectorString(std::vector<std::string>& args) {
    char** argv = new char*[args.size()];
    for (size_t i = 0; i < args.size(); ++i) {
        argv[i] = const_cast<char*>(args[i].c_str());
    }
    return argv;
}

TEST(ParseConsoleTest, OKFile) {
    int64_t argc = 2;
    // Запускаемый тест находится в /cmake-build-debug/test
    std::vector<std::string> args{"gamer_club", "../../test/input.txt"};
    ASSERT_NO_THROW(ParserConsole(argc, CastVectorString(args)));
}

TEST(ParseConsoleTest, NoSuchFile) {
    int64_t argc = 2;
    std::vector<std::string> args{"gamer_club", "INPUT.txt"};
    ASSERT_THROW(ParserConsole(argc, CastVectorString(args)), ParserConsoleException);
}

TEST(ParseConsoleTest, WrongExtention) {
    int64_t argc = 2;
    std::vector<std::string> args{"gamer_club", "../../test/input.py"};
    ASSERT_THROW(ParserConsole(argc, CastVectorString(args)), ParserConsoleException);
}
