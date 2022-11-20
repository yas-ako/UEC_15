#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

void layer_1(double t)
{
  struct color c3 = {255, 0, 0};
  img_fillcircle(c3, t, t, 10);
}