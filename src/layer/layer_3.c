#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"
#define BUILDING 8

double point[BUILDING][2]; //建物の座標リスト
int diff[BUILDING] = {
    0,
    100,
    150,
    230,
    300,
    320,
    440,
    550,
}; //建物のずれのリスト

// int x1 = 0;
// int y1_ = 0;
// int x2 = 0;
// int y2 = 0;
// int x3 = 0;
// int y3 = 0;
// int x4 = 0;
// int y4 = 0;
// int x5 = 0;
// int y5 = 0;
// int x6 = 0;
// int y6 = 0;

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
  for (int i = 0; i < BUILDING; i++)
  {
    point[i][0] = (int)(t * 600 + diff[i]) % WIDTH; //建物のx座標を，ずれのリストdiffを使って求める
    point[i][1] = HEIGHT / 3;
  }

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

  // int n = t / WIDTH;
  // int y1_offset = HEIGHT / 3;
  // // x1 = (int)(t + 0.5) % 60 + 720 * n * 600;
  // x1 = (int)(t * 600 + 0.5) % WIDTH;
  // y1_ = y1_offset;

  // int y2_offset = HEIGHT / 3;
  // // x2 = (int)(t + 0.5) % 60 - 200 + 720 * n * 600;
  // x2 = (int)(t * 600 - 95.5) % WIDTH;
  // y2 = y2_offset;

  // int y3_offset = HEIGHT / 3;
  // // x3 = (int)(t + 0.5) % 60 - 500 + 720 * n * 600;
  // x3 = (int)(t * 600 - 155.5) % WIDTH;
  // y3 = y3_offset;

  // int y4_offset = HEIGHT / 3;
  // // x3 = (int)(t + 0.5) % 60 - 500 + 720 * n * 600;
  // x4 = (int)(t * 600 - 205.5) % WIDTH;
  // y4 = y4_offset;

  // int y5_offset = HEIGHT / 3;
  // // x3 = (int)(t + 0.5) % 60 - 500 + 720 * n * 600;
  // x5 = (int)(t * 600 - 315.5) % WIDTH;
  // y5 = y5_offset;

  // int y6_offset = HEIGHT / 3;
  // // x3 = (int)(t + 0.5) % 60 - 500 + 720 * n * 600;
  // x6 = (int)(t * 600 - 495.5) % WIDTH;
  // y6 = y6_offset;
};

//建物の色指定
struct color c3_1 = {255, 255, 255};
struct color c3_2 = {255, 150, 150};
struct color c3_3 = {150, 150, 150};

void building(int type, double t)
{
  lay_3_xy(t);
  double list[][2] = {{40, 28}, {28, 18}, {15, 25}, {20, 7}, {60, 30}, {40, 20}, {20, 60}, {50, 30}};
  for (int i = 0; i < BUILDING; i++)
  {
    img_fillrect(c3_1, point[type][0], point[type][1], list[type][0], list[type][1]);
  }
}
/*
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
}*/

void layer_3(double t)
{
  struct color c3 = {40, 55, 0};
  // img_fillcircle(c3, t * 3, t * 3, 10);
  // lay_3_xy(t);
  // layer_3_1(t);
  for (int i = 0; i < BUILDING; i++)
  {
    building(i, t);
  }
}
