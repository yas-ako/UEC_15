#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

void layer_1(double t)
{
  struct color c1 = {30, 30, 255};
  struct color c2 = {255, 255, 255};

  // int i;
  // for (i = 0; t < 20; ++i)
  // {
  img_filltriangle(c1, 120 + t * 8, 360, 20 + t * 8, 180, 140 + t * 8, 360, 120 + t * 8, 360, 240 + t * 8, 180, 240 + t * 8, 180);
  img_filltriangle(c2, 125 + t * 8, 369, 120 + t * 8, 360, 135 + t * 8, 369, 125 + t * 8, 369, 140 + t * 8, 360, 140 + t * 8, 360);
  // }
}