
#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//窓と架線柱
void layer_5(double t)
{
  struct color c5 = {128, 128, 128};
  struct color white = {255, 255, 255};

  //架線柱
  img_fillline(c5, 0 + (int)(t * 3600 + 0.5) % (WIDTH * 2), 480, 0 + (int)(t * 3600 + 0.5) % (WIDTH * 2), 0, 25);

  //窓枠
  img_fillline(white, 0, 0, 0, HEIGHT, WIDTH / 5);
  img_fillline(white, WIDTH, HEIGHT, WIDTH, 0, WIDTH / 5);
}
