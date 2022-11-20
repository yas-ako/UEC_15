#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//市街地
void layer_3(double t)
{
  struct color c3 = {40, 55, 0};
  img_fillcircle(c3, t * 3, t * 3, 10);
}