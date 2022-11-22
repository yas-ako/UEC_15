#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//窓と電柱
void layer_5(double t)
{
  struct color c3 = {40, 55, 0};
  img_fillcircle(c3, t * WIDTH , WIDTH / 2, 10);

}