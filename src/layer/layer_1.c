#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

void layer_1(double t)
{
  struct color c1 = {0, 0, 255};
  struct color c2 = {255, 255, 255};

  // int i;
  // for (i = 0; t < 20; ++i)
  // {
  img_filltriangle(c1, 120 + t * 8, 180, 20 + t * 8, 20, 140 + t * 8, 180, 120 + t * 8, 180, 240 + t * 8, 20, 240 + t * 8, 20);
  img_filltriangle(c2, 120 + t * 8, 180, 100 + t * 8, 160, 140 + t * 8, 180, 120 + t * 8, 180, 160 + t * 8, 160, 160 + t * 8, 160);
  // }
}