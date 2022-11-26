#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"
#include <math.h>
void layer_0(void)
{
  double y_times = 0;
  struct color y_colour = {103, 159, 242};
  for (int y_times = 0; y_times < HEIGHT; y_times++)
  {
    double times_factor = pow(1.02, y_times / 2);
    y_colour.r = 113 - times_factor;
    y_colour.g = 159 - times_factor;
    y_colour.b = 242;
    for (int i = 0; i < 720; i++)
    {
      img_putpixel(y_colour, i, y_times + 1);
    }
  }
}
