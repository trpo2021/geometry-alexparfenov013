#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(suite, system_testing)
{
    ASSERT_EQUAL(1 + 2, 3);
}

CTEST(name_check, incorrect_name)
{
    char* checkingstring = "circle(1* 2*, 3)";

    int real = checkingexceptionCheckingSomeSymbols(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckingSomeSymbols(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char* checkingstring = "circle(1, 2, 3)";

    int real = checkingexceptionCheckMoreOneComma(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckMoreOneComma(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char* checkingstring = "circle(1 2 3)";

    int real = checkingexceptionCheckComma(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckComma(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char* checkingstring = "circle((1 2, 3))";

    int real = checkingexceptionCheckingOnTwoBrackets(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckingOnTwoBrackets(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char* checkingstring = "circle 1 2, 3";

    int real = checkingexceptionCheckingOnBracket(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char* checkingstring = "circle (1 2, 3)";

    int real = checkingexceptionCheckingOnBracket(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name)
{
    char *checkingstring = "(1 2, 3)circle", *checkingwordcircle = "circle";

    int real = checkingexceptionPosCircle(checkingstring, checkingwordcircle);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char *checkingstring = "circle(1 2, 3)", *checkingwordcircle = "circle";

    int real = checkingexceptionPosCircle(checkingstring, checkingwordcircle);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_1)
{
    char* checkingstring = "circle(1. 2, 3)";

    int real = checkingOtherExceptions(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, incorrect_name_2)
{
    char* checkingstring = "circle(. 2, 3)";

    int real = checkingOtherExceptions(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(name_check, correct_name)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingOtherExceptions(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}
