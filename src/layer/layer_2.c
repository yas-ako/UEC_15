#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//低い山
void layer_2(double t)
{
  struct color c3 = {40, 55, 0};
  // img_fillcircle(c3, t * 2, t * 2, 10);
  // img_putpixel

  // struct color c3 = {40, 55, 0};
  // img_fillcircle(c3, t * WIDTH , WIDTH / 2, 10);
  Point p1;
  Point p2;
  Point p3;
  Point p4;

  p1.x = 50;
  p1.y = 60;
  p2.x = 80;
  p2.y = 80;
  p3.x = 90;
  p3.y = 30;
  p4.x = 50;
  p4.y = 20;

  Polygon polygon1;
  polygon1.n = 4;
  polygon1.p[0] = p1;
  polygon1.p[1] = p2;
  polygon1.p[2] = p3;
  polygon1.p[3] = p4;
  img_fillpolygon(c3, polygon1);
}