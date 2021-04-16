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

int checkingOtherExceptions(char* checkingstring)
{
    char str[100][100], pr[] = "( ) ,", checkingstringtemp[200];
    char checkingwordcircle[100] = "circle";
    char* tmp;
    int i = 0, flag = 0;
    strcpy(checkingstringtemp, checkingstring);
    tmp = strtok(checkingstring, pr);
    while (tmp != NULL) {
        strncpy(str[i], tmp, 100);
        tmp = strtok(NULL, pr);
        i++;
    }

    ////////////////
    char* postempcomma;
    int poscomma;
    postempcomma = strchr(checkingstringtemp, ',');
    poscomma = postempcomma - checkingstringtemp + 1;
    ///////////////////////////
    int numberofelements = i;
    ////////////////////////////////////////////////////////////
    char* postempvaluey;
    int positionvaluey;
    postempvaluey = strstr(checkingstringtemp, str[2]);
    positionvaluey = postempvaluey - checkingstringtemp + 1;
    if (poscomma < positionvaluey) {
        flag = 1;
    }

    //////////////////////////////////////////////
    if (str[1][0] == '.') {
        flag = 1;
    }
    if (flag == 0)
        if (str[2][0] == '.') {
            flag = 1;
        }
    if (flag == 0)
        if (str[3][0] == '.') {
            flag = 1;
        }
    ///////////////////////////////////////////
    if (str[1][0] == '0' && str[1][1] == '0') {
        flag = 1;
    }

    if (flag == 0) {
        if (str[2][0] == '0' && str[2][1] == '0') {
            flag = 1;
        }
    }
    if (flag == 0) {
        if (str[3][0] == '0' && str[3][1] == '0') {
            flag = 1;
        }
    }
    ///////////////////////////////////////////
    char* tempforstrchecking;
    int checkingpositiondot = 1;
    int checkingStrLenx;
    int checkingStrLeny;
    int checkingStrLenr;
    checkingStrLenx = strlen(str[1]);
    checkingStrLeny = strlen(str[2]);
    checkingStrLenr = strlen(str[3]);
    if (strchr(str[1], '.') != NULL) {
        tempforstrchecking = strchr(str[1], '.');
        checkingpositiondot = tempforstrchecking - str[1] + 1;
        if (checkingpositiondot == checkingStrLenx) {
            flag = 1;
        }
    }
    checkingpositiondot = 0;
    if (flag == 0)
        if (strchr(str[2], '.') != NULL) {
            tempforstrchecking = strchr(str[2], '.');
            checkingpositiondot = tempforstrchecking - str[2] + 1;
            if (checkingpositiondot == checkingStrLeny) {
                flag = 1;
            }
        }

    checkingpositiondot = 0;
    if (flag == 0)
        if (strchr(str[3], '.') != NULL) {
            tempforstrchecking = strchr(str[3], '.');
            checkingpositiondot = tempforstrchecking - str[3] + 1;
            if (checkingpositiondot == checkingStrLenr) {
                flag = 1;
            }
        }

    char templast = '~';
    if (flag == 0)
        for (char tempA = 'A'; tempA <= templast; tempA++) {
            if (strchr(str[1], tempA) != NULL) {
                flag = 1;
            }
        }
    if (flag == 0)
        for (char tempA = 'A'; tempA <= templast; tempA++) {
            if (strchr(str[2], tempA) != NULL) {
                flag = 1;
            }
        }
    if (flag == 0)
        for (char tempA = 'A'; tempA <= templast; tempA++) {
            if (strchr(str[3], tempA) != NULL) {
                flag = 1;
            }
        }
    if (numberofelements > 4) {
        printf("Error at column 15: unexpected token \n");
        flag = 1;
    }
    if (numberofelements < 4) {
        flag = 1;
    }
    if (strcmp(str[0], checkingwordcircle) != 0) {
        flag = 1;
    }
    return flag;
}
