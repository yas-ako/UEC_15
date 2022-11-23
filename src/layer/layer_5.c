#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//窓と電柱
void layer_5(double t)
{
  struct color c5 = {128, 128, 128};
  img_fillline(c5, 0 + t * 8, 480, 0 + t * 8, 0, 25);
}
