#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//窓と電柱
void layer_5(double t)
{
  struct color c3 = {40, 55, 0};
  // img_fillcircle(c3, t * WIDTH , WIDTH / 2, 10);
  Point p1;
  Point p2;
  Point p3;
  Point p4;

  p1.x = 60;
  p1.y = 40;
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