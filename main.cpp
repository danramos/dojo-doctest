#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include <string>

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
        int whole = static_cast<int>(_number);
        if (whole > 1) {
            return std::to_string(whole / 2) +
                std::to_string(whole - 2);
        }
        return std::to_string(whole);
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

TEST_CASE("2.0 is represented as 10")
{
    BinaryFractionGenerator generator(2.0);
    CHECK("10" == generator.str());
}

