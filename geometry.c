#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void circle(float x, float y, float r);
const double pi = 3.14;
int main()
{
    float checktypefloat = 0;
    char checkingstring[200], str[100][100], pr[] = "( ) ,";
    char checkingwordcircle[100] = "circle";
    char *tmp, *p1, *p2;
    int i = 0;
    printf("Введите строку: ");
    fgets(checkingstring, sizeof(checkingstring), stdin);
    p1 = strchr(checkingstring, ')');
    p2 = strrchr(checkingstring, ')');
    checkingstring[strlen(checkingstring) - 1] = '\0';
    int checkingexceptions = 0;
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
    if (p1 == NULL) {
        printf("Error at column 12: expected ','\n");
        checkingexceptions = 1;
    }
    tmp = strtok(checkingstring, pr);
    while (tmp != NULL) {
        strncpy(str[i], tmp, 100);
        tmp = strtok(NULL, pr);
        i++;
    }
    int numberofelements = i;
    int checkexceptionstypedouble = 0;
    float znacheniex;
    float znacheniey;
    float znachenieR;
    ////////////////////////////////////////////////////////////
    if (strchr(str[1], 'a') != NULL || strchr(str[1], 'b') != NULL
        || strchr(str[1], 'c') != NULL || strchr(str[1], 'd') != NULL
        || strchr(str[1], 'e') != NULL || strchr(str[1], 'f') != NULL
        || strchr(str[1], 'g') != NULL || strchr(str[1], 'h') != NULL
        || strchr(str[1], 'i') != NULL || strchr(str[1], 'j') != NULL
        || strchr(str[1], 'k') != NULL || strchr(str[1], 'l') != NULL
        || strchr(str[1], 'm') != NULL || strchr(str[1], 'n') != NULL
        || strchr(str[1], 'o') != NULL || strchr(str[1], 'p') != NULL
        || strchr(str[1], 'q') != NULL || strchr(str[1], 'r') != NULL
        || strchr(str[1], 's') != NULL || strchr(str[1], 't') != NULL
        || strchr(str[1], 'u') != NULL || strchr(str[1], 'v') != NULL
        || strchr(str[1], 'w') != NULL || strchr(str[1], 'x') != NULL
        || strchr(str[1], 'y') != NULL || strchr(str[1], 'z') != NULL
        || strchr(str[1], 'A') != NULL || strchr(str[1], 'B') != NULL
        || strchr(str[1], 'C') != NULL || strchr(str[1], 'D') != NULL
        || strchr(str[1], 'E') != NULL || strchr(str[1], 'F') != NULL
        || strchr(str[1], 'G') != NULL || strchr(str[1], 'H') != NULL
        || strchr(str[1], 'I') != NULL || strchr(str[1], 'J') != NULL
        || strchr(str[1], 'K') != NULL || strchr(str[1], 'L') != NULL
        || strchr(str[1], 'M') != NULL || strchr(str[1], 'N') != NULL
        || strchr(str[1], 'O') != NULL || strchr(str[1], 'P') != NULL
        || strchr(str[1], 'Q') != NULL || strchr(str[1], 'R') != NULL
        || strchr(str[1], 'S') != NULL || strchr(str[1], 'T') != NULL
        || strchr(str[1], 'U') != NULL || strchr(str[1], 'V') != NULL
        || strchr(str[1], 'W') != NULL || strchr(str[1], 'X') != NULL
        || strchr(str[1], 'Y') != NULL || strchr(str[1], 'Z') != NULL) {
        printf("Error at column 7: expected '<double>'\n");
        checkingexceptions = 1;
        checkexceptionstypedouble = 1;
    }
    if (checkexceptionstypedouble == 0)
        if (strchr(str[2], 'a') != NULL || strchr(str[2], 'b') != NULL
            || strchr(str[2], 'c') != NULL || strchr(str[2], 'd') != NULL
            || strchr(str[2], 'e') != NULL || strchr(str[2], 'f') != NULL
            || strchr(str[2], 'g') != NULL || strchr(str[2], 'h') != NULL
            || strchr(str[2], 'i') != NULL || strchr(str[2], 'j') != NULL
            || strchr(str[2], 'k') != NULL || strchr(str[2], 'l') != NULL
            || strchr(str[2], 'm') != NULL || strchr(str[2], 'n') != NULL
            || strchr(str[2], 'o') != NULL || strchr(str[2], 'p') != NULL
            || strchr(str[2], 'q') != NULL || strchr(str[2], 'r') != NULL
            || strchr(str[2], 's') != NULL || strchr(str[2], 't') != NULL
            || strchr(str[2], 'u') != NULL || strchr(str[2], 'v') != NULL
            || strchr(str[2], 'w') != NULL || strchr(str[2], 'x') != NULL
            || strchr(str[2], 'y') != NULL || strchr(str[2], 'z') != NULL
            || strchr(str[2], 'A') != NULL || strchr(str[2], 'B') != NULL
            || strchr(str[2], 'C') != NULL || strchr(str[2], 'D') != NULL
            || strchr(str[2], 'E') != NULL || strchr(str[2], 'F') != NULL
            || strchr(str[2], 'G') != NULL || strchr(str[2], 'H') != NULL
            || strchr(str[2], 'I') != NULL || strchr(str[2], 'J') != NULL
            || strchr(str[2], 'K') != NULL || strchr(str[2], 'L') != NULL
            || strchr(str[2], 'M') != NULL || strchr(str[2], 'N') != NULL
            || strchr(str[2], 'O') != NULL || strchr(str[2], 'P') != NULL
            || strchr(str[2], 'Q') != NULL || strchr(str[2], 'R') != NULL
            || strchr(str[2], 'S') != NULL || strchr(str[2], 'T') != NULL ||

            strchr(str[2], 'U') != NULL || strchr(str[2], 'V') != NULL
            || strchr(str[2], 'W') != NULL || strchr(str[2], 'X') != NULL
            || strchr(str[2], 'Y') != NULL || strchr(str[2], 'Z') != NULL) {
            printf("Error at column 7: expected '<double>'\n");
            checkingexceptions = 1;
            checkexceptionstypedouble = 1;
        }
    if (checkexceptionstypedouble == 0)
        if (strchr(str[3], 'a') != NULL || strchr(str[3], 'b') != NULL
            || strchr(str[3], 'c') != NULL || strchr(str[3], 'd') != NULL
            || strchr(str[3], 'e') != NULL || strchr(str[3], 'f') != NULL
            || strchr(str[3], 'g') != NULL || strchr(str[3], 'h') != NULL ||

            strchr(str[3], 'i') != NULL || strchr(str[3], 'j') != NULL
            || strchr(str[3], 'k') != NULL || strchr(str[3], 'l') != NULL
            || strchr(str[3], 'm') != NULL || strchr(str[3], 'n') != NULL
            || strchr(str[3], 'o') != NULL || strchr(str[3], 'p') != NULL
            || strchr(str[3], 'q') != NULL || strchr(str[3], 'r') != NULL
            || strchr(str[3], 's') != NULL || strchr(str[3], 't') != NULL
            || strchr(str[3], 'u') != NULL || strchr(str[3], 'v') != NULL
            || strchr(str[3], 'w') != NULL || strchr(str[3], 'x') != NULL
            || strchr(str[3], 'y') != NULL || strchr(str[3], 'z') != NULL
            || strchr(str[3], 'A') != NULL || strchr(str[3], 'B') != NULL
            || strchr(str[3], 'C') != NULL || strchr(str[3], 'D') != NULL
            || strchr(str[3], 'E') != NULL || strchr(str[3], 'F') != NULL
            || strchr(str[3], 'G') != NULL || strchr(str[3], 'H') != NULL
            || strchr(str[3], 'I') != NULL || strchr(str[3], 'J') != NULL
            || strchr(str[3], 'K') != NULL || strchr(str[3], 'L') != NULL
            || strchr(str[3], 'M') != NULL || strchr(str[3], 'N') != NULL
            || strchr(str[3], 'O') != NULL || strchr(str[3], 'P') != NULL
            || strchr(str[3], 'Q') != NULL || strchr(str[3], 'R') != NULL
            || strchr(str[3], 'S') != NULL || strchr(str[3], 'T') != NULL
            || strchr(str[3], 'U') != NULL || strchr(str[3], 'V') != NULL
            || strchr(str[3], 'W') != NULL || strchr(str[3], 'X') != NULL
            || strchr(str[3], 'Y') != NULL || strchr(str[3], 'Z') != NULL) {
            printf("Error at column 7: expected '<double>'\n");
            checkingexceptions = 1;
            checkexceptionstypedouble = 1;
        }
    if (checkexceptionstypedouble != 1) {
        znacheniex = atof(str[1]);
        znacheniey = atof(str[2]);
        znachenieR = atof(str[3]);
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

    if (sizeof(znacheniex) == sizeof(checktypefloat)
        && sizeof(znacheniey) == sizeof(checktypefloat)
        && sizeof(znachenieR) == sizeof(checktypefloat))
        printf("%c", '\0');
    else {
        printf("Error at column 7: expected '<double>'");
        checkingexceptions = 1;
    }
    if (checkingexceptions == 1) {
        printf("For example: circle (x y, r)\n");
    }
    if (checkingexceptions == 0) {
        printf("All correct\n");
    }
}
////////////////////////////////////////////////
// void circle(float x, float y, float r)
// {
// double perimetr = 0;
// double area = 0;
// perimetr = 2 * pi * r;
// area = pi * r * r;
// printf("perimetr = %.4f\narea = %.4f \n", perimetr, area);
// }
