#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

// 富士山
void layer_1(double t)
{
  struct color c1 = {30, 30, 255};
  struct color c2 = {255, 255, 255};

  // img_filltriangle(c1, 120 + t *1, 360, 20 + t *1, 180, 140 + t *1, 360, 120 + t *1, 360, 240 + t *1, 180, 240 + t *1, 180);

  img_filltriangle(c1, 160 + t * 1, 260, -40 + t * 1, 160, 240 + t * 1, 260, 160 + t * 1, 260, 440 + t * 1, 160, 440 + t * 1, 160);
  img_filltriangle(c1, 180 + t * 1, 300, 20 + t * 1, 180, 220 + t * 1, 300, 180 + t * 1, 300, 380 + t * 1, 180, 380 + t * 1, 180);
  
  // img_filltriangle(c2, 125 + t *1, 369, 120 + t *1, 360, 135 + t *1, 369, 125 + t *1, 369, 140 + t *1, 360, 140 + t *1, 360);
  
  img_filltriangle(c2, 180 + t * 1, 300, 132 + t * 1, 264, 220 + t * 1, 300, 180 + t * 1, 300, 268 + t * 1, 264, 268 + t * 1, 264);
}
