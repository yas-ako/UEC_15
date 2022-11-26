#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"
#include <math.h>
void layer_0(void)
{
  double y_times = 0;
  struct color y_colour_init = {125, 140, 255};
  for (int y_times = 0; y_times < HEIGHT; y_times++)
  {
    double times_factor = pow(1.01, y_times);
    struct color y_colour = {125 + times_factor, 140 + times_factor, 255};
    if (y_colour.g > 255)
    {
      y_colour.g = 255;
    }
    for (int i = 0; i < 720; i++)
    {
      img_putpixel(y_colour, i, 480 - (y_times + 1) );
    }
  }
}