#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"

#include <string>

std::string lookAndSay(const std::string& current) {
    return current + "-say what?!";
}

TEST_CASE("Next af a single number is 1 of that number")
{
    CHECK(lookAndSay("1") == "11");
    CHECK(lookAndSay("2") == "12");
    CHECK(lookAndSay("3") == "13");
}

TEST_CASE("Next of same two numbers is 2 of that number")
{
    CHECK(lookAndSay("11") == "21");
    CHECK(lookAndSay("22") == "22");
    CHECK(lookAndSay("33") == "23");
}

TEST_CASE("Two different numbers")
{
    CHECK(lookAndSay("12") == "1112");
    CHECK(lookAndSay("23") == "1213");
    CHECK(lookAndSay("21") == "1211");
}

TEST_CASE("Three same numbers")
{
    CHECK(lookAndSay("111") == "31");
    CHECK(lookAndSay("222") == "32");
    CHECK(lookAndSay("333") == "33");
}

TEST_CASE("Three numbers all different")
{
    CHECK(lookAndSay("123") == "111213");
    CHECK(lookAndSay("213") == "121113");
    CHECK(lookAndSay("321") == "131211");
}

TEST_CASE("Three numbers where the first 2 are the same")
{
    CHECK(lookAndSay("112") == "2112");
    CHECK(lookAndSay("122") == "1122");
}

/**
 *  Refactor your code to be more generic.
 *  Tests must not break during this process.
 *  Make small transformations in your code that would lead you into a writing a loop
 */

TEST_CASE("Generated sequence")
{
    CHECK(lookAndSay("1") == "11");
    CHECK(lookAndSay("11") == "21");
    CHECK(lookAndSay("21") == "1211");
    CHECK(lookAndSay("1211") == "111221");
    CHECK(lookAndSay("111221") == "312211");
    CHECK(lookAndSay("312211") == "13112221");
}
