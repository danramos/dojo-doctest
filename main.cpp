#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include <string>
#include <sstream>
#include <iostream>

/**
 * Do not change
 *
 */

class BinaryFractionGenerator
{
public:
    BinaryFractionGenerator(float x) : _number(x)
    {
    }

    std::string str()
    {
        std::string result;
        int whole = static_cast<int>(_number);
        auto fraction = _number - whole;

        do {
            result = std::to_string(whole % 2) + result;
            whole = whole / 2;
        } while (whole);


        if (fraction)
            result += ".";

        if (fraction)
        {
            auto temp = fraction * 2;
            auto whole = static_cast<int>(temp);

            result += std::to_string(whole);
            fraction = temp - whole;

            if (fraction) {
                auto temp = fraction * 2;
                auto whole = static_cast<int>(temp);
                result += std::to_string(whole);

                fraction = temp - whole;
                if (fraction)
                {
                    result += "1";
                }
            }
        }

        return result;
    }

private:
    float _number;
};

TEST_CASE("0d is represented as 0.0")
{
    BinaryFractionGenerator generator(0.0);
    CHECK("0" == generator.str());
}

TEST_CASE("1.0 is represented as 1")
{
    BinaryFractionGenerator generator(1.0);
    CHECK("1" == generator.str());
}

TEST_CASE("2.0 is represented as 10, 3.0 is represented as 11")
{
    BinaryFractionGenerator generator(2.0);
    CHECK("10" == generator.str());

    BinaryFractionGenerator generator2(3.0);
    CHECK("11" == generator2.str());
}

TEST_CASE("4.0 is represented as 100")
{
    BinaryFractionGenerator generator(4.0);
    CHECK("100" == generator.str());

    BinaryFractionGenerator generator2(5.0);
    CHECK("101" == generator2.str());
}

TEST_CASE("9.0 is represented as 1001")
{
    BinaryFractionGenerator generator(9.0);
    CHECK("1001" == generator.str());

    BinaryFractionGenerator generator2(13.0);
    CHECK("1101" == generator2.str());

    BinaryFractionGenerator generator3(15.0);
    CHECK("1111" == generator3.str());
}

TEST_CASE("0.5 is represented as 0.1")
{
    BinaryFractionGenerator generator(0.5);
    CHECK("0.1" == generator.str());
}

TEST_CASE("0.25 is represented as 0.01")
{
    BinaryFractionGenerator generator(0.25);
    CHECK("0.01" == generator.str());
}

TEST_CASE("0.75 is represented as 0.11")
{
    BinaryFractionGenerator generator(0.75);
    CHECK("0.11" == generator.str());
}

TEST_CASE("0.625 is represented by 0.101")
{
    BinaryFractionGenerator generator(0.625);
    CHECK("0.101" == generator.str());
}
