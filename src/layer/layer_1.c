#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

// 富士山
void layer_1(double t)
{
  struct color c1 = {30, 30, 255};
  struct color c2 = {255, 255, 255};

  img_filltriangle(c1, 160 + t * 5, 260, -40 + t * 5, 160, 240 + t * 5, 260, 160 + t * 5, 260, 440 + t * 5, 160, 440 + t * 5, 160);
  img_filltriangle(c1, 180 + t * 5, 300, 20 + t * 5, 180, 220 + t * 5, 300, 180 + t * 5, 300, 380 + t * 5, 180, 380 + t * 5, 180);
  img_filltriangle(c2, 180 + t * 5, 300, 132 + t * 5, 264, 220 + t * 5, 300, 180 + t * 5, 300, 268 + t * 5, 264, 268 + t * 5, 264);
}
