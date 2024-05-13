#include <gtest/gtest.h>
#include "../TimeStamp.h"

TEST(TimeStampTest, ConstructorStringOKTest) {
    std::string raw = "14:50";
    TimeStamp ts(raw);
    EXPECT_EQ(ts.hours, 14);
    EXPECT_EQ(ts.minutes, 50);

    std::string raw1 = "00:00";
    TimeStamp ts1(raw1);
    EXPECT_EQ(ts1.hours, 0);
    EXPECT_EQ(ts1.minutes, 0);

    std::string raw2 = "01:07";
    TimeStamp ts2(raw2);
    EXPECT_EQ(ts2.hours, 1);
    EXPECT_EQ(ts2.minutes, 7);

    std::string raw3 = "20:09";
    TimeStamp ts3(raw3);
    EXPECT_EQ(ts3.hours, 20);
    EXPECT_EQ(ts3.minutes, 9);

    std::string raw4 = "05:49";
    TimeStamp ts4(raw4);
    EXPECT_EQ(ts4.hours, 5);
    EXPECT_EQ(ts4.minutes, 49);
}

TEST(TimeStampTest, ConstructorStringErrorTest) {
    EXPECT_ANY_THROW({
        std::string raw1 = "00.00";
        TimeStamp ts(raw1);};);
    EXPECT_ANY_THROW({
         std::string raw1 = "10 43";
         TimeStamp ts(raw1);};);
    EXPECT_ANY_THROW({
        std::string raw1 = "101:4233";
        TimeStamp ts(raw1);};);
    EXPECT_ANY_THROW({
        std::string raw1 = "101:42";
        TimeStamp ts(raw1);};);
    EXPECT_ANY_THROW({
        std::string raw1 = "10:430";
        TimeStamp ts(raw1);};);
    EXPECT_ANY_THROW({
        std::string raw1 = "-10:430";
        TimeStamp ts(raw1);};);
    EXPECT_ANY_THROW({
        std::string raw1 = "10:60";
        TimeStamp ts(raw1);};);
    EXPECT_ANY_THROW({
        std::string raw1 = "24:30";
        TimeStamp ts(raw1);};);
}
