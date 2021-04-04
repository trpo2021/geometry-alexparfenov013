#include "libgeometry/geometry.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const double pi = 3.14;

void circlevoid(float x, float y, float r)
{
    double perimetr = 0;
    double area = 0;
    perimetr = 2 * pi * r;
    area = pi * r * r;
    printf("perimetr = %.4f\narea = %.4f \n circle coordinates x - %.4f \n y - "
           "%.4f \n",
           perimetr,
           area,
           x,
           y);
}
int checkingexceptionPosCircle(char* checkingstring, char* checkingwordcircle)
{
    int flag = 0;
    char* postempcircle;
    int poscircle;
    postempcircle = strstr(checkingstring, checkingwordcircle);
    poscircle = postempcircle - checkingstring + 1;
    if (poscircle != 1) {
        flag = 1;
    }
    return flag;
}

int checkingexceptionCheckingOnBracket(char* checkingstring)
{
    int flag = 0;
    char* p1;
    p1 = strchr(checkingstring, ')');
    if (p1 == NULL) {
        flag = 1;
    }
    p1 = strchr(checkingstring, '(');
    if (p1 == NULL) {
        flag = 1;
    }
    return flag;
}

int checkingexceptionCheckingOnTwoBrackets(char* checkingstring)
{
    int flag = 0;
    char *p1, *p2;
    p1 = strchr(checkingstring, ')');
    p2 = strrchr(checkingstring, ')');
    if (p1 != p2) {
        flag = 1;
    }
    p1 = strchr(checkingstring, '(');
    p2 = strrchr(checkingstring, '(');
    if (p1 != p2) {
        flag = 1;
    }
    return flag;
}

int checkingexceptionCheckComma(char* checkingstring)
{
    int flag = 0;
    char* p1;
    p1 = strchr(checkingstring, ',');
    if (p1 == NULL) {
        flag = 1;
    }
    return flag;
}

int checkingexceptionCheckMoreOneComma(char* checkingstring)
{
    int flag = 0;
    char *p1, *p2;
    p1 = strchr(checkingstring, ',');
    p2 = strrchr(checkingstring, ',');
    if (p1 != p2) {
        flag = 1;
    }
    return flag;
}

int checkingexceptionCheckingSomeSymbols(char* checkingstring)
{
    int flag = 0;
    char tempZ = '&';
    for (char tempA = '!'; tempA <= tempZ; tempA++) {
        if (strchr(checkingstring, tempA) != NULL) {
            flag = 1;
        }
    }
    if (strchr(checkingstring, '/') != NULL
        || strchr(checkingstring, '+') != NULL
        || strchr(checkingstring, '*') != NULL
        || strchr(checkingstring, 39) != NULL) {
        flag = 1;
    }
    return flag;
}
