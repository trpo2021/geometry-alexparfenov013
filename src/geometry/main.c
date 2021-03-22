#include "libgeometry/geometry.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double pi = 3.14;
int main()
{

    char checkingstring[200], str[100][100], pr[] = "( ) ,",
                                             checkingstringtemp[200];
    char checkingwordcircle[100] = "circle";
    int checkexceptionstypedouble = 0;
    int checkingexceptions = 0;
    char *tmp, *p1, *p2;
    int i = 0;
    printf("Введите строку: ");
    fgets(checkingstring, sizeof(checkingstring), stdin);
    p1 = strchr(checkingstring, ')');
    p2 = strrchr(checkingstring, ')');
    checkingstring[strlen(checkingstring) - 1] = '\0';
    if (p1 == NULL) {
        printf("Error at column 13: expected ')'\n");
        checkingexceptions = 1;
    }
    if (p1 != p2) {
        printf("Error at column 16: expected only one ')'\n");
        checkingexceptions = 1;
    }
    p1 = strchr(checkingstring, '(');
    p2 = strrchr(checkingstring, '(');
    if (p1 == NULL) {
        printf("Error at column 13: expected '('\n");
        checkingexceptions = 1;
    }
    if (p1 != p2) {
        printf("Error at column 16: expected only one '('\n");
        checkingexceptions = 1;
    }
    p1 = strchr(checkingstring, ',');
    p2 = strrchr(checkingstring, ',');
    if (p1 == NULL) {
        printf("Error at column 12: expected ','\n");
        checkingexceptions = 1;
    }
    if (p1 != p2) {
        printf("Error at column 17: expected only one ','\n");
        checkingexceptions = 1;
    }
    char tempZ = '&';
    for (char tempA = '!'; tempA <= tempZ; tempA++) {
        if (strchr(checkingstring, tempA) != NULL) {
            printf("Error at column 7: expected '<double>'\n");
            checkingexceptions = 1;
            checkexceptionstypedouble = 1;
        }
    }
    if (strchr(checkingstring, '/') != NULL
        || strchr(checkingstring, '+') != NULL
        || strchr(checkingstring, '*') != NULL
        || strchr(checkingstring, 39) != NULL) {
        printf("Error at column 7: expected '<double>'\n");
        checkingexceptions = 1;
        checkexceptionstypedouble = 1;
    }
    ////////////////
    char* postempcomma;
    int poscomma;
    postempcomma = strchr(checkingstring, ',');
    poscomma = postempcomma - checkingstring + 1;
    strcpy(checkingstringtemp, checkingstring);
    ///////////////////////////
    char* postempcircle;
    int poscircle;
    postempcircle = strstr(checkingstring, checkingwordcircle);
    poscircle = postempcircle - checkingstring + 1;
    if (poscircle != 1) {
        printf("Error at column 25: you need to write circle on 1st position "
               "without space \n");
        checkingexceptions = 1;
    }
    tmp = strtok(checkingstring, pr);
    while (tmp != NULL) {
        strncpy(str[i], tmp, 100);
        tmp = strtok(NULL, pr);
        i++;
    }
    int numberofelements = i;
    int checkingexceptionsdotbeforenumber = 0;
    ////////////////////////////////////////////////////////////
    char* postempvaluey;
    int positionvaluey;
    postempvaluey = strstr(checkingstringtemp, str[2]);
    positionvaluey = postempvaluey - checkingstringtemp + 1;
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
    int checkingpositiondot = 0, checkingpositiondotexceptions = 0;
    if (strchr(str[1], '.') != NULL) {
        tempforstrchecking = strchr(str[1], '.');
        checkingpositiondot = tempforstrchecking - str[1] + 1;
        if (checkingpositiondot == strlen(str[1])) {
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
            if (checkingpositiondot == strlen(str[2])) {
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
            if (checkingpositiondot == strlen(str[3])) {
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
    circle(valuex, valuey, valuer);
    }
    if (checkingexceptions == 1) {
        printf("For example: circle (x y, r)\n");
    }
}
