#include "libgeometry/geometry.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char checkingstring[200],str[100][100],pr[] = "( ) ,";
    char checkingstringtemp2[200], *tmp;
    char checkingwordcircle[100] = "circle";
    int checkingexceptions = 0, i = 0;
    printf("Введите строку: ");
    fgets(checkingstring, sizeof(checkingstring), stdin);
    checkingstring[strlen(checkingstring) - 1] = '\0';
    strcpy(checkingstringtemp2, checkingstring);
    tmp = strtok(checkingstringtemp2, pr);
    while (tmp != NULL) {
        strncpy(str[i], tmp, 100);
        tmp = strtok(NULL, pr);
        i++;
    }
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
        checkingexceptions = 1;
    }
    if (checkingOtherExceptions(checkingstring)) {
        printf("Error at column you have exceptions maybe with type double or "
               "with position dot or another exception\n");
        checkingexceptions = 1;
    }
    if (checkingexceptions == 0) {
    	float valuex = atof(str[1]);
        float valuey = atof(str[2]);
        float valuer = atof(str[3]);
        circlevoid(valuex, valuey, valuer);
    }
}

