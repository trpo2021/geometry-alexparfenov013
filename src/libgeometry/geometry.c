#include "libgeometry/geometry.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void circlevoid(float x, float y, float r);
const double pi=3.14;

void circlevoid(float x, float y, float r)
{

double perimetr = 0;
double area = 0;
perimetr = 2 * pi * r;
area = pi * r * r;
printf("perimetr = %.4f\narea = %.4f \n circle coordinates x - %.4f \n y - %.4f \n", perimetr, area, x, y);
}
