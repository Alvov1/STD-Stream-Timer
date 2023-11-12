#include <gtest/gtest.h>
#include "../Timer.h"

#include <thread>
#include <regex>

TEST(MainTest, COut) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

#include "usage_case.txt"

    std::cout.rdbuf(oldCout);

    constexpr auto pattern = R"(\[0 ms\] Hello, World!\n\[\d{4,} ms\] Were here after 2,5 seconds\.\n\[\d{4,} ms\] And here we are after 0,75 seconds more.\n)";
    std::smatch match;
    const auto string = buffer.str();

    EXPECT_TRUE(std::regex_match(string, match, std::regex(pattern)));
}