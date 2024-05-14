#include <gtest/gtest.h>
#include "../GamerClubEnv.h"
#include "../ParserFile.h"
#include <sstream>

std::vector<std::string> MySplit(std::string& str, char del=' ') {
    std::string tmp;
    std::vector<std::string> v;
    for (char i : str){
        if (i != del) {
            tmp += i;
        } else{
            v.push_back(tmp);
            tmp.clear();
        }
    }
    v.push_back(tmp);
    return v;
}

std::string workoutWrong(ParserFile& pf) {
    try {
        GamerClubEnv env(pf.tablesNum, pf.costPerHour, pf.startWorkTime, pf.endWorkTime, pf.inputEventsQueue);
        env.HandleInputEvents();
        std::stringstream buffer;
        std::streambuf *oldbuff = std::cout.rdbuf(buffer.rdbuf());
        env.Print();
        std::string output = buffer.str();
        std::cout.rdbuf(oldbuff);
        return output;
    } catch (const ParserFileError& pfe) {
        return pfe.what();
    }
}

std::string getbufOutput(std::string& filename) {
    ParserFile pf(filename);
    GamerClubEnv env(pf.tablesNum, pf.costPerHour, pf.startWorkTime, pf.endWorkTime, pf.inputEventsQueue);
    env.HandleInputEvents();
    std::stringstream buffer;
    std::streambuf *oldbuff = std::cout.rdbuf(buffer.rdbuf());
    env.Print();
    std::string output = buffer.str();
    std::cout.rdbuf(oldbuff);
    return output;
}

TEST(EnvTest, CommonOutput1) {
    std::string parcerfile = "../../test/input.txt";
    std::string output = getbufOutput(parcerfile);
    std::string correctOutput = "09:00\n"
                                "08:48 1 client1\n"
                                "08:48 13 NotOpenYet\n"
                                "09:41 1 client1\n"
                                "09:48 1 client2\n"
                                "09:52 3 client1\n"
                                "09:52 13 ICanWaitNoLonger\n"
                                "09:54 2 client1 1\n"
                                "10:25 2 client2 2\n"
                                "10:58 1 client3\n"
                                "10:59 2 client3 3\n"
                                "11:30 1 client4\n"
                                "11:35 2 client4 2\n"
                                "11:35 13 PlaceIsBusy\n"
                                "11:45 3 client4\n"
                                "12:33 4 client1\n"
                                "12:33 12 client4 1\n"
                                "12:43 4 client2\n"
                                "15:52 4 client4\n"
                                "19:00 11 client3\n"
                                "19:00\n"
                                "1 70 05:58\n"
                                "2 30 02:18\n"
                                "3 90 08:01\n";
    EXPECT_EQ(output,correctOutput);
}

TEST(EnvTest, CommonOutput2) {
    std::string parcerfile = "../../test/input2.txt";
    std::string output = getbufOutput(parcerfile);
    std::string correctOutPut = "10:00\n"
                                "10:00 1 client1\n"
                                "10:00 1 client1\n"
                                "10:00 13 YouShallNotPass\n"
                                "20:00\n"
                                "1 0 00:00\n"
                                "2 0 00:00\n"
                                "3 0 00:00\n"
                                "4 0 00:00\n";
    EXPECT_EQ(output, correctOutPut);
}

TEST(EnvTest, CommonOutput3) {
    std::string parcerfile = "../../test/input3.txt";
    std::string output = getbufOutput(parcerfile);
    std::string correctOutPut = "10:00\n10:00 1 c1\n"
                                "10:00 2 c1 3\n"
                                "20:00 11 c1\n"
                                "20:00\n"
                                "1 0 00:00\n"
                                "2 0 00:00\n"
                                "3 100 10:00\n"
                                "4 0 00:00\n";
    EXPECT_EQ(output, correctOutPut);
}

TEST(EnvTest, CommonOutput4) {
    std::string parcerfile = "../../test/input4.txt";
    std::string output = getbufOutput(parcerfile);
    std::string correctOutPut = "08:00\n"
                                "17:00\n"
                                "1 0 00:00\n"
                                "2 0 00:00\n"
                                "3 0 00:00\n"
                                "4 0 00:00\n"
                                "5 0 00:00\n";
    EXPECT_EQ(output, correctOutPut);
}

TEST(EnvTest, CommonOutput5) {
    std::string parcerfile = "../../test/input5.txt";
    std::string output = getbufOutput(parcerfile);
    std::string correctOutPut = "08:00\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "17:00\n"
                                "1 0 00:00\n"
                                "2 0 00:00\n"
                                "3 0 00:00\n"
                                "4 0 00:00\n"
                                "5 0 00:00\n";
    EXPECT_EQ(output, correctOutPut);
}

TEST(EnvTest, CommonOutput6) {
    std::string parcerfile = "../../test/input6.txt";
    std::string output = getbufOutput(parcerfile);
    std::string correctOutPut = "08:00\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1a\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "10:00 4 c1\n"
                                "10:00 13 ClientUnknown\n"
                                "17:00\n"
                                "1 0 00:00\n"
                                "2 0 00:00\n"
                                "3 0 00:00\n"
                                "4 0 00:00\n"
                                "5 0 00:00\n";
    EXPECT_EQ(output, correctOutPut);
}

TEST(EnvTest, CommonOutput7) {
    std::string parcerfile = "../../test/input16.txt";
    std::string output = getbufOutput(parcerfile);
    std::string correctOutPut = "09:00\n"
                                "08:58 1 d\n"
                                "08:58 13 NotOpenYet\n"
                                "08:59 1 d\n"
                                "08:59 13 NotOpenYet\n"
                                "09:00 1 d\n"
                                "09:01 2 d 1\n"
                                "09:02 4 d\n"
                                "09:03 1 d\n"
                                "09:04 2 d 1\n"
                                "09:05 4 d\n"
                                "09:06 1 d\n"
                                "09:07 2 d 1\n"
                                "09:08 4 d\n"
                                "09:09 1 d\n"
                                "09:10 2 d 1\n"
                                "09:11 4 d\n"
                                "09:12 1 d\n"
                                "09:13 2 d 1\n"
                                "09:14 4 d\n"
                                "09:15 1 d\n"
                                "09:16 2 d 1\n"
                                "09:17 4 d\n"
                                "09:18 1 d\n"
                                "09:19 2 d 1\n"
                                "09:20 4 d\n"
                                "09:21 1 d\n"
                                "09:22 2 d 1\n"
                                "09:23 4 d\n"
                                "09:25 1 d\n"
                                "09:26 2 d 1\n"
                                "10:30 11 d\n"
                                "10:30\n"
                                "1 10 01:12\n";
    EXPECT_EQ(output, correctOutPut);
}

