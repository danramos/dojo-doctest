#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include <string>
#include <sstream>
#include <iostream>

std::string to_binary(float _number)
{
    std::string result;
    int whole = static_cast<int>(_number);
    float fraction = _number - whole;

    do {
        result = std::to_string(whole % 2) + result;
        whole = whole / 2;
    } while (whole);

    if (fraction)
    {
        result += ".";
        while (fraction)
        {
            const auto temp = fraction * 2;
            const auto whole = static_cast<int>(temp);
            result += std::to_string(whole);
            fraction = temp - whole;
        }
    }
    return result;
}


TEST_CASE("0d is represented as 0.0")
{
    CHECK("0" == to_binary(0.0));
}

TEST_CASE("1.0 is represented as 1")
{
    CHECK("1" == to_binary(1.0));
}

TEST_CASE("2.0 is represented as 10, 3.0 is represented as 11")
{
    CHECK("10" == to_binary(2.0));
    CHECK("11" == to_binary(3.0));
}

TEST_CASE("4.0 is represented as 100")
{
    CHECK("100" == to_binary(4.0));
    CHECK("101" == to_binary(5.0));
}

TEST_CASE("9.0 is represented as 1001")
{
    CHECK("1001" == to_binary(9.0));
    CHECK("1101" == to_binary(13.0));
    CHECK("1111" == to_binary(15.0));
}

TEST_CASE("0.5 is represented as 0.1")
{
    CHECK("0.1" == to_binary(0.5));
}

TEST_CASE("0.25 is represented as 0.01")
{
    CHECK("0.01" == to_binary(0.25));
}

TEST_CASE("0.75 is represented as 0.11")
{
    CHECK("0.11" == to_binary(0.75));
}

TEST_CASE("0.625 is represented by 0.101")
{
    CHECK("0.101" == to_binary(0.625));
}

TEST_CASE("0.625 is represented by 0.101")
{
    CHECK("0.101" == to_binary(0.625));
    CHECK("0.011" == to_binary(0.375));
}

TEST_CASE("0.5625 is represented by 0.1001")
{
    CHECK("0.1001" == to_binary(0.5625));
}

TEST_CASE("13.625 is represented by 1101.101")
{
    CHECK("1101.101" == to_binary(13.625));
}

TEST_CASE("0.2 is an infinite binary decimal, so why is it terminated here")
{
    CHECK("0.00110011001100110011001101" == to_binary(0.2));
}

/**
 * CHALLENGE!!!
 * Modify code such that you get the first 200 bits in 0.2 binary expansion"
 */
/*
TEST_CASE("More digits, the better")
{
    CHECK("0.0011001100110011001100110011001100110011001100110011001100110011001100110011001100110011001100110011" == to_binary(0.2));
}
*/

