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
        int whole = static_cast<int>(_number);
        const auto result = std::to_string(whole);
        return result;
    }

private:
    /*
    std::string getWholeRepresentation(int whole)
    {
    }
    */

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

/*
TEST_CASE("4.0 is represented as 100")
{
    BinaryFractionGenerator generator(4.0);
    CHECK("100" == generator.str());
}
*/

