#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

void layer_2(double t)
{
  struct color c3 = {40, 55, 0};
  img_fillcircle(c3, t * 2, t * 2, 10);
}