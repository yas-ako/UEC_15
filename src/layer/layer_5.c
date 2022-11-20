#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

void layer_5(double t)
{
  struct color c3 = {40, 55, 0};
  img_fillcircle(c3, t * 5, t * 5, 10);
}