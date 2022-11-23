#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

int x1 = 0;
int y1_ = 0;
int x2 = 0;
int y2 = 0;
int x3 = 0;
int y3 = 0;

//市街地

void img_fillrect(struct color c, double x, double y, double w, double h)
{
  int wmin = (int)(x), wmax = (int)(x + w);
  int hmin = (int)(y), hmax = (int)(y + h);
  int i, j;
  for (j = hmin; j <= hmax; ++j)
  {
    for (i = wmin; i <= wmax; ++i)
    {
      img_putpixel(c, i, j);
    }
  }
}

//市街地
//建物サイズを決める
//建物の左下の座標を計算
int lay_3_xy(double t)
{
  // int n = t / 720;
  // int y1_offset = 0;
  // int x1 = (int)(t + 0.5) % 60 + 720 * n;
  // int  y1_ = y1_offset;

  // int y2_offset = 0;
  // int x2 = (int)(t + 0.5) % 60 - 200 + 720 * n;
  // int y2 = y2_offset;

  // int y3_offset = 0;
  // int x3 = (int)(t + 0.5) % 60 - 500 + 720 * n;
  // int y3 = y3_offset;

  int n = t / WIDTH;
  int y1_offset = HEIGHT / 3;
  // x1 = (int)(t + 0.5) % 60 + 720 * n * 600;
  x1 = (int)(t * 600 + 0.5) % WIDTH;
  y1_ = y1_offset;

  int y2_offset = HEIGHT / 3;
  // x2 = (int)(t + 0.5) % 60 - 200 + 720 * n * 600;
  x2 = (int)(t * 600 - 195.5) % WIDTH;
  y2 = y2_offset;

  int y3_offset = HEIGHT / 3;
  // x3 = (int)(t + 0.5) % 60 - 500 + 720 * n * 600;
  x3 = (int)(t * 600 - 495.5) % WIDTH;
  y3 = y3_offset;
};

//建物の色指定
struct color c3_1 = {255, 255, 255};
struct color c3_2 = {255, 150, 150};
struct color c3_3 = {150, 150, 150};

void layer_3_1(double t)
{
  lay_3_xy(t);
  struct color c = c3_1;
  double x = x1;
  double y = y1_;
  double w = 40;
  double h = 28;

  img_fillrect(c, x, y, w, h);
}

void layer_3_2(double t)
{
  lay_3_xy(t);
  struct color c = c3_2;
  double x = x2;
  double y = y2;
  double w = 28;
  double h = 18;

  img_fillrect(c, x, y, w, h);
}

void layer_3_3(double t)
{
  lay_3_xy(t);
  struct color c = c3_3;
  double x = x3;
  double y = y3;
  double w = 15;
  double h = 25;

  img_fillrect(c, x, y, w, h);
}

void layer_3(double t)
{
  struct color c3 = {40, 55, 0};
  // img_fillcircle(c3, t * 3, t * 3, 10);
  // lay_3_xy(t);
  layer_3_1(t);
  layer_3_2(t);
  layer_3_3(t);
}
