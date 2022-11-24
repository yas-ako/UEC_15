
#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"

//建物の数
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
};

//建物の色指定
struct color c3_1 = {255, 255, 255};
struct color c3_2 = {255, 150, 150};
struct color c3_3 = {150, 150, 150};

//建物を描画
void building(int type, double t)
{
  lay_3_xy(t);
  // 建物の縦横の幅のリスト
  double list[][2] = {{40, 28}, {28, 18}, {15, 25}, {20, 7}, {60, 30}, {40, 20}, {20, 60}, {50, 30}};
  for (int i = 0; i < BUILDING; i++)
  {
    img_fillrect(c3_1, point[type][0], point[type][1], list[type][0], list[type][1]);
  }
}

void layer_3(double t)
{
  struct color c3 = {40, 55, 0};

  for (int i = 0; i < BUILDING; i++)
  {
    building(i, t);
  }
}
