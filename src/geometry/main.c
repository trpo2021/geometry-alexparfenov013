#include "libgeometry/geometry.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char checkingstring[200], str[100][100], pr[] = "( ) ,",
                                             checkingstringtemp[200];
    char checkingwordcircle[100] = "circle";
    int checkexceptionstypedouble = 0;
    int checkingexceptions = 0;
    char* tmp;
    int i = 0;
    printf("Введите строку: ");
    fgets(checkingstring, sizeof(checkingstring), stdin);
    checkingstring[strlen(checkingstring) - 1] = '\0';
    if (checkingexceptionCheckingOnBracket(checkingstring)) {
        printf("Error at column 13: expected ')' or '('\n");
        checkingexceptions = 1;
    }
    if (checkingexceptionCheckingOnTwoBrackets(checkingstring)) {
        printf("Error at column 16: find two or more ')' or '('\n");
        checkingexceptions = 1;
    }
    if (checkingexceptionCheckComma(checkingstring)) {
        printf("Error at column 12: expected ','\n");
        checkingexceptions = 1;
    }
    if (checkingexceptionCheckMoreOneComma(checkingstring)) {
        printf("Error at column 17: expected only one ','\n");
        checkingexceptions = 1;
    }
    if (checkingexceptionPosCircle(checkingstring, checkingwordcircle)) {
        printf("Error at column 25: you need to write circle on 1st position "
               "without space \n");
        checkingexceptions = 1;
    }
    if (checkingexceptionCheckingSomeSymbols(checkingstring)) {
        printf("Error at column 7: expected '<double>'\n");
        checkexceptionstypedouble = 1;
        checkingexceptions = 1;
    }
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
    poscomma = postempcomma  - checkingstringtemp + 1;
    ///////////////////////////
    int numberofelements = i;
    int checkingexceptionsdotbeforenumber = 0;
    ////////////////////////////////////////////////////////////
    char* postempvaluey;
    int positionvaluey;
    postempvaluey = strstr(checkingstringtemp, str[2]);
    positionvaluey = postempvaluey - checkingstringtemp+ 1;
    if (poscomma < positionvaluey) {
        printf("Error at column 24: , not before value R \n");
        checkingexceptions = 1;
    }

    //////////////////////////////////////////////
    if (str[1][0] == '.') {
        printf("Error at column 20: . before element\n");
        checkingexceptions = 1;
        checkingexceptionsdotbeforenumber = 1;
    }
    if (checkingexceptionsdotbeforenumber == 0)
        if (str[2][0] == '.') {
            printf("Error at column 20: . before element\n");
            checkingexceptions = 1;
            checkingexceptionsdotbeforenumber = 1;
        }
    if (checkingexceptionsdotbeforenumber == 0)
        if (str[3][0] == '.') {
            printf("Error at column 20: . before element\n");
            checkingexceptions = 1;
            checkingexceptionsdotbeforenumber = 1;
        }
    ///////////////////////////////////////////
    int checkingexceptionstwozero = 0;
    if (str[1][0] == '0' && str[1][1] == '0') {
        printf("Error at column 23: you need 0.1 0.5 0.05 no 00\n");
        checkingexceptions = 1;
        checkingexceptionstwozero = 1;
    }

    if (checkingexceptionstwozero == 0) {
        if (str[2][0] == '0' && str[2][1] == '0') {
            printf("Error at column 23: you need 0.1 0.5 0.05 no 00\n");
            checkingexceptions = 1;
            checkingexceptionstwozero = 1;
        }
    }
    if (checkingexceptionstwozero == 0) {
        if (str[3][0] == '0' && str[3][1] == '0') {
            printf("Error at column 23: you need 0.1 0.5 0.05 no 00\n");
            checkingexceptions = 1;
            checkingexceptionstwozero = 1;
        }
    }
    ///////////////////////////////////////////
    char* tempforstrchecking;
    int checkingpositiondot = 1, checkingpositiondotexceptions = 0;
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
            printf("Error at column 22: number. you need to write value after "
                   "dot \n");
            checkingexceptions = 1;
            checkingpositiondotexceptions = 1;
        }
    }
    checkingpositiondot = 0;
    if (checkingpositiondotexceptions == 0)
        if (strchr(str[2], '.') != NULL) {
            tempforstrchecking = strchr(str[2], '.');
            checkingpositiondot = tempforstrchecking - str[2] + 1;
            if (checkingpositiondot == checkingStrLeny) {
                printf("Error at column 22: number. you need to write value "
                       "after dot \n");
                checkingexceptions = 1;

                checkingpositiondotexceptions = 1;
            }
        }

    checkingpositiondot = 0;
    if (checkingpositiondotexceptions == 0)
        if (strchr(str[3], '.') != NULL) {
            tempforstrchecking = strchr(str[3], '.');
            checkingpositiondot = tempforstrchecking - str[3] + 1;
            if (checkingpositiondot == checkingStrLenr) {
                printf("Error at column 22: number. you need to write value "
                       "after dot \n");
                checkingexceptions = 1;
                checkingpositiondotexceptions = 1;
            }
        }

    char templast = '~';
    if (checkexceptionstypedouble == 0)
        for (char tempA = 'A'; tempA <= templast; tempA++) {
            if (strchr(str[1], tempA) != NULL) {
                printf("Error at column 7: expected '<double>'\n");
                checkingexceptions = 1;
                checkexceptionstypedouble = 1;
            }
        }
    if (checkexceptionstypedouble == 0)
        for (char tempA = 'A'; tempA <= templast; tempA++) {
            if (strchr(str[2], tempA) != NULL) {
                printf("Error at column 7: expected '<double>'\n");
                checkingexceptions = 1;
                checkexceptionstypedouble = 1;
            }
        }
    if (checkexceptionstypedouble == 0)
        for (char tempA = 'A'; tempA <= templast; tempA++) {
            if (strchr(str[3], tempA) != NULL) {
                printf("Error at column 7: expected '<double>'\n");
                checkingexceptions = 1;
                checkexceptionstypedouble = 1;
            }
        }
    if (numberofelements > 4) {
        printf("Error at column 15: unexpected token \n");
        checkingexceptions = 1;
    }
    if (numberofelements < 4) {
        printf("Error at column 14: you need to write x,y and R in () \n");
        checkingexceptions = 1;
    }
    if (strcmp(str[0], checkingwordcircle) != 0) {
        printf("Error at column 0: expected 'circle'\n");
        checkingexceptions = 1;
    }
    if (checkingexceptions == 0) {
        float valuex = atof(str[1]);
        float valuey = atof(str[2]);
        float valuer = atof(str[3]);
        circlevoid(valuex, valuey, valuer);
    }
    if (checkingexceptions == 1) {
        printf("For example: circle (x y, r)\n");
    }
}

