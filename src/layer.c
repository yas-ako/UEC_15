// animate1 --- create animation using img lib.
#include "img.h"
static int imgNumber = 0;

int main(void)
{
  struct color c1 = {30, 255, 0};
  struct color c2 = {255, 0, 0};
  int i;

  for (i = 0; i < TIME / DELAY; ++i)
  {
    img_clear();
    layer_1((i / 100.0) * DELAY);
    layer_2((i / 100.0) * DELAY);
    layer_3((i / 100.0) * DELAY);
    layer_4((i / 100.0) * DELAY);
    layer_5((i / 100.0) * DELAY);
    // layer_2((i * DELAY) / 100);
    img_putpixel(c1, WIDTH / 2, HEIGHT / 2);
    img_fillcircle(c1, 20 + i * 8, 100, 20);
    img_write();
  }

  // for (i = 0; i < 20; ++i)
  // {
  //   img_clear();
  //   img_fillcircle(c2, 180, 100 + i * 5, 20 - i);
  //   img_write();
  // }
}
