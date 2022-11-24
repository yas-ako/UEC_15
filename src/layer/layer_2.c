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

  Polygon polygon1; //初めから見えているポリゴン
  Polygon polygon2; //最初は左に隠れていて、少しずつ見えてくるポリゴン
  polygon1.n = points_number;
  polygon2.n = points_number;

  for (int i = 0; i < points_number; i++)
  {

    Point p1;
    p1.x = 5 * t + points_list[i][0];
    p1.y = points_list[i][1];
    polygon1.p[i] = p1;

    p1.x = 5 * t + points_list[i][0] - WIDTH; //同じ多角形の山を、画面の幅分だけ左にずらす。
    p1.y = points_list[i][1];
    polygon2.p[i] = p1;

  }

  img_fillpolygon(c3, polygon1);
  img_fillpolygon(c3, polygon2);
}