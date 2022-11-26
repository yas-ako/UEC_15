#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

struct color field = {190, 209, 44};

void layer_4(double t)
{
  img_fillrect(field, 0, 30, WIDTH, 130);
}
