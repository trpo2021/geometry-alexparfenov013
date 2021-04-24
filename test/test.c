#include "ctest.h"
#include "libgeometry/geometry.h"

CTEST(namecheck1, incorrectname1)
{
    char* checkingstring = "circle(1* 2*, 3)";

    int real = checkingexceptionCheckingSomeSymbols(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck2, correctname2)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckingSomeSymbols(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck3, incorrectname3)
{
    char* checkingstring = "circle(1, 2, 3)";

    int real = checkingexceptionCheckMoreOneComma(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck4, correctname4)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckMoreOneComma(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck5, incorrectname5)
{
    char* checkingstring = "circle(1 2 3)";

    int real = checkingexceptionCheckComma(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck6, correctname6)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckComma(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck7, incorrectname7)
{
    char* checkingstring = "circle((1 2, 3))";

    int real = checkingexceptionCheckingOnTwoBrackets(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck8, correctname8)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingexceptionCheckingOnTwoBrackets(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck9, incorrectname9)
{
    char* checkingstring = "circle 1 2, 3";

    int real = checkingexceptionCheckingOnBracket(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck10, correctname10)
{
    char* checkingstring = "circle (1 2, 3)";

    int real = checkingexceptionCheckingOnBracket(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck11, incorrectname11)
{
    char *checkingstring = "(1 2, 3)circle", *checkingwordcircle = "circle";

    int real = checkingexceptionPosCircle(checkingstring, checkingwordcircle);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck12, correctname12)
{
    char *checkingstring = "circle(1 2, 3)", *checkingwordcircle = "circle";

    int real = checkingexceptionPosCircle(checkingstring, checkingwordcircle);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck13, incorrectname13)
{
    char* checkingstring = "circle(1. 2, 3)";

    int real = checkingOtherExceptions(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck14, incorrectname14)
{
    char* checkingstring = "circle(. 2, 3)";

    int real = checkingOtherExceptions(checkingstring);

    int exp = 1;

    ASSERT_EQUAL(exp, real);
}

CTEST(namecheck15, correctname15)
{
    char* checkingstring = "circle(1 2, 3)";

    int real = checkingOtherExceptions(checkingstring);

    int exp = 0;

    ASSERT_EQUAL(exp, real);
}
