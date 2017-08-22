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
        std::string result;

        auto remainder = whole % 2;
        whole = whole / 2;

        result = std::to_string(remainder) + result;
        if (whole)
        {
            remainder = whole % 2;
            whole = whole / 2;

            result = std::to_string(remainder) + result;

            if (whole)
            {
                result = std::to_string(whole) + result;
            }
        }

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

TEST_CASE("4.0 is represented as 100")
{
    BinaryFractionGenerator generator(4.0);
    CHECK("100" == generator.str());

    BinaryFractionGenerator generator2(5.0);
    CHECK("101" == generator2.str());
}
/*
TEST_CASE("9.0 is represented as 1001")
{
    BinaryFractionGenerator generator(9.0);
    CHECK("1001" == generator.str());

    BinaryFractionGenerator generator2(13.0);
    CHECK("1101" == generator2.str());

    BinaryFractionGenerator generator3(15.0);
    CHECK("1111" == generator2.str());


}
*/
