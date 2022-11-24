
#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//窓と電柱
void layer_5(double t)
{
  struct color c5 = {128, 128, 128};

  //線を引く
  img_fillline(c5, 0 + (int)(t * 3600 + 0.5) % (WIDTH * 2), 480, 0 + (int)(t * 3600 + 0.5) % (WIDTH * 2), 0, 25);
}
