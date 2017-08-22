#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include <string>
#include <sstream>

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
        std::stringstream ss;

        int whole = static_cast<int>(_number);

        std::string result;

        auto remainder = whole % 2;
        if (whole > 1) {
            auto quotient = whole / 2;
            ss << quotient;
        }

        ss << remainder;
        return ss.str();
    }

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


