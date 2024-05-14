#include <gtest/gtest.h>
#include "../ParserFile.h"

TEST(ParserFileTest, CorrectData) {
    ASSERT_NO_THROW({
        std::string path="../../test/input.txt";
        ParserFile parserFile(path);
    };);

    ASSERT_NO_THROW({
        std::string path="../../test/input5.txt";
        ParserFile parserFile(path);
    };);

    ASSERT_NO_THROW({
        std::string path="../../test/input5.txt";
        ParserFile parserFile(path);
    };);

    ASSERT_NO_THROW({
        std::string path="../../test/input4.txt";
        ParserFile parserFile(path);
    };);
}

TEST(ParserFileTest, WrongData) {
    // Кол-во столов
    ASSERT_THROW({
         std::string path="../../test/input7.txt";
         ParserFile parserFile(path);
    };, ParserFileError);

    ASSERT_THROW({
         std::string path="../../test/input8.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
    // Время
    ASSERT_THROW({
         std::string path="../../test/input9.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
    // Цена
    ASSERT_THROW({
         std::string path="../../test/input10.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
    // Сбитая хронология
    ASSERT_THROW({
         std::string path="../../test/input11.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
    // Неправильное имя
    ASSERT_THROW({
         std::string path="../../test/input12.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
    // Неправильный формат времени событий
    ASSERT_THROW({
         std::string path="../../test/input13.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
    // Стол больше чем число столов
    ASSERT_THROW({
         std::string path="../../test/input14.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
    // неправильный порядок
    ASSERT_THROW({
         std::string path="../../test/input15.txt";
         ParserFile parserFile(path);
     };, ParserFileError);
}