#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//低い山
void layer_2(double t)
{
  int points_number = 11;

  int points_list[][2] = {
      {-1, 174},
      {94, 226},
      {175, 195},
      {288, 206},
      {409, 190},
      {530, 214},
      {634, 168},
      {690, 185},
      {720, 174},
      {720, -1},
      {-1, -1},
  };

  struct color c3 = {40, 55, 0};
  // img_fillcircle(c3, t * 2, t * 2, 10);
  // img_putpixel

  // struct color c3 = {40, 55, 0};
  // img_fillcircle(c3, t * WIDTH , WIDTH / 2, 10);
  // Point p1;
  // Point p2;
  // Point p3;
  // Point p4;

  // p1.x = 5 * t + 50;
  // // p1.y = 5 * t + 60;
  // p1.y = 60;
  // p2.x = 5 * t + 80;
  // // p2.y = 5 * t + 80;
  // p2.y = 80;
  // p3.x = 5 * t + 90;
  // // p3.y = 5 * t + 30;
  // p3.y = 30;
  // p4.x = 5 * t + 50;
  // // p4.y = 5 * t + 20;
  // p4.y = 20;

  Polygon polygon1;
  Polygon polygon2;
  polygon1.n = points_number;
  polygon2.n = points_number;
  // polygon1.p[0] = p1;
  // polygon1.p[1] = p2;
  // polygon1.p[2] = p3;
  // polygon1.p[3] = p4;

  for (int i = 0; i < points_number; i++)
  {
    Point p1;
    p1.x = 5 * t + points_list[i][0];
    p1.y = points_list[i][1];
    polygon1.p[i] = p1;

    p1.x = 5 * t + points_list[i][0] - WIDTH;
    p1.y = points_list[i][1];
    polygon2.p[i] = p1;

    // Point p2;
  }

  struct color vertex = {20, 20, 20};
  img_fillpolygon(c3, polygon1);
  img_fillpolygon(c3, polygon2);

  // for (int i = 0; i < points_number; i++)
  // {
  //   img_putpixel(vertex, points_list[i][0], points_list[i][1]);
  // }
}