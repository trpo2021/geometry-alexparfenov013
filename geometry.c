
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void circle(int x, int y, float r);
const double pi = 3.14;
int main()
{
    int m = 0;
    float l = 0;
    char stroka[200], str[100][100], pr[] = "( ) ,";
    char checka[100] = "circle";
    char *tmp, *p;
    int i = 0;
    printf("Введите строку: ");
    fgets(stroka, sizeof(stroka), stdin);
    p = strchr(stroka, ')');
    stroka[strlen(stroka) - 1] = '\0';
    int flag = 0;
    if (p == NULL) {
        printf("Error at column 13: expected ')'\n");
        flag = 1;
    }
    tmp = strtok(stroka, pr);
    while (tmp != NULL) {
        strncpy(str[i], tmp, 100);
        tmp = strtok(NULL, pr);
        i++;
    }
    int n = i;
    int checkpoint = 0;
    int number1;
    int number2;
    float number3;
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
        flag = 1;
        checkpoint = 1;
    }
    if (flag == 0)
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
            || strchr(str[2], 'S') != NULL || strchr(str[2], 'T') != NULL
            || strchr(str[2], 'U') != NULL || strchr(str[2], 'V') != NULL
            || strchr(str[2], 'W') != NULL || strchr(str[2], 'X') != NULL
            || strchr(str[2], 'Y') != NULL || strchr(str[2], 'Z') != NULL) {
            printf("Error at column 7: expected '<double>'\n");
            flag = 1;
            checkpoint = 1;
        }
    if (flag == 0)
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
            flag = 1;
            checkpoint = 1;
        }
    if (checkpoint != 1) {
        number1 = atoi(str[1]);
        number2 = atoi(str[2]);
        number3 = atof(str[3]);
    }
    if (n > 4) {
        printf("Error at column 15: unexpected token \n");
        flag = 1;
    }
    if (strcmp(str[0], checka) != 0) {
        printf("Error at column 0: expected 'circle'\n");
        flag = 1;
    }

    if (sizeof(number1) == sizeof(m) && sizeof(number2) == sizeof(m)
        && sizeof(number3) == sizeof(l))
        printf("%c", '\0');
    else {
        printf("Error at column 7: expected '<double>'");
        flag = 1;
    }
    if (flag == 0) {
        printf("All correct\n");
    }
}
////////////////////////////////////////////////
// void circle(int x, int y, float r)
// {
// double perimetr = 0;
// double area = 0;
// perimetr = 2 * pi * r;
// area = pi * r * r;
// printf("perimetr = %.4f\narea = %.4f \n", perimetr, area);
// }
