#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "..\img.h"
// vector
// {
//   double x;
//   double y;
// };

// double get_length(vector v)
// {
// }
/*
//ベクトルの長さを計算する
double get_vector_length(vector v)
{
  return pow((v.x * v.x) + (v.y * v.y), 0.5);
}

//ベクトル内積
double dot_product(vector vl, vector vr)
{
  // printf("%f %f %f %f %f\n", vl.x, vr.x, vl.y, vr.y, vl.x * vr.x + vl.y * vr.y);
  return vl.x * vr.x + vl.y * vr.y;
}

//２つのベクトルABのなす角度θを求める
double AngleOf2Vector(vector A, vector B)
{
  //ベクトルAとBの長さを計算する
  double length_A = get_vector_length(A);
  double length_B = get_vector_length(B);
  // printf("%f  %f\n", length_A * length_B, dot_product(A, B));
  //内積とベクトル長さを使ってcosθを求める
  double cos_sita = dot_product(A, B) / (length_A * length_B);
  // printf("%f\n", cos_sita);

  // cosθからθを求める
  double sita = acos(cos_sita);
  // double sita = acos(1.1);
  // printf("%f\n", sita);

  //ラジアンでなく0～180の角度でほしい場合はコメント外す
  sita = sita * 180.0 / M_PI;

  return sita;
}*/

int IsInPolygon(Point point, Polygon polygon)
{

  double degree = 0; //角度の合計を入れる変数を定義
  Point p1;
  Point p2;
  Point p3;
  //一つ目の点のデータを展開
  p1.x = point.x;
  p1.y = point.y;
  for (int i = 0; i < polygon.n; i++)
  {
    // degree = 0;
    // 二つ目の点を取得
    p2.x = polygon.p[i].x;
    p2.y = polygon.p[i].y;
    // 二つ目の点の次がないのなら，
    if (i + 1 == polygon.n)
    {
      // 次の点のデータを取得
      p3.x = polygon.p[0].x;
      p3.y = polygon.p[0].y;
      // printf("  1 :%f %f\n", p3.x, p3.y);
    }
    else
    {
      // printf("2");
      // 一番最初の値を取得
      p3.x = polygon.p[i + 1].x;
      p3.y = polygon.p[i + 1].y;
      // printf("  2 :%f %f\n", p3.x, p3.y);
    }
    // printf("    %f,%f %f,%f %f,%f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    // /*
    double ax = p2.x - p1.x;
    double ay = p2.y - p1.y;
    double bx = p3.x - p1.x;
    double by = p3.y - p1.y;
    // printf("1 %f\n", ax * bx + ay * by);
    // printf("%f %f %f %f\n", ax, ay, bx, by);
    // printf("2 %f\n", (sqrt(ax * ax + ay * ay) * sqrt(bx * bx + by * by)));

    // double a = ax * bx + ay * by;
    // double b = sqrt(ax * ax + ay * ay);
    // b *= b < 0 ? -1 : 1;
    // double c = sqrt(bx * bx + by * by);
    // c *= c < 0 ? -1 : 1;
    // double d = b * c;

    // double cosine = a / d;
    double cosine = (ax * bx + ay * by) / (sqrt(ax * ax + ay * ay) * sqrt(bx * bx + by * by));
    double g = ax * by - ay * bx;
    // printf("%f %f\n", cosine, g);
    // printf("3 %f\n", cosine);
    cosine = acos(cosine) * 180.0 / M_PI;
    // degree = degree + (acos(cosine) * 180.0) / M_PI;

    // double e = acos(cosine);
    // e = e * 180.0 / M_PI;
    // degree = degree + e;
    // printf("%f\n", degree);
    // */
    // sita = sita * 180.0 / M_PI;
    // degree += AngleOf3Points(p1, p2, p3); // * 180.0 / M_PI; //  点のデータをAngleOf3Points()に入れて，戻り値を取得

    degree += copysign(cosine, g);
  }
  // printf(": %f\n", degree);

  // if 角度の合計が，0.01以下である
  // if (degree >= 390)// && degree >= 340)
  // {
  //   // printf("a");
  //   // degree = 0.0;
  //   return 1;
  // }
  // else
  // {
  //   // degree == 0;
  //   return 0;
  // }
  if (fabs(degree) >= 0.01)
  {
    return 1;
  }
  return 0;
}
/*
//多角形の隣り合った2点と，調べたい点のなす角を求める
double AngleOf3Points(Point point1, Point point2, Point point3)
{
  vector oa;
  vector ob;
  oa.x = point2.x - point1.x;
  oa.y = point2.y - point1.y;
  ob.x = point3.x - point1.x;
  ob.y = point3.y - point1.y;
  double angle = AngleOf2Vector(oa, ob);
  // printf("%f\n", angle);
  return angle;
}

Polygon max_min_point(Polygon polygon)
{
  int minX = WIDTH;
  int maxX = 0;
  int minY = WIDTH;
  int maxY = 0;
  // for polygonを順に展開
  for (int i = 0; i < polygon.n; i++)
  {
    if (minX > polygon.p[i].x)
    {
      //   もし，minXが，polygon[繰り返し変数].x より大きければ，
      //       minX = polygon[繰り返し変数].x
      minX = polygon.p[i].x;
    }
    if (minY > polygon.p[i].y)
    {
      //   もし，minYが，polygon[繰り返し変数].y より大きければ，
      //       minY = polygon[繰り返し変数].y
      minY = polygon.p[i].y;
    }

    if (maxX < polygon.p[i].x)
    {
      //   もし，minXが，polygon[繰り返し変数].x より大きければ，
      //       minX = polygon[繰り返し変数].x
      maxX = polygon.p[i].x;
    }
    if (maxY < polygon.p[i].y)
    {
      //   もし，minYが，polygon[繰り返し変数].y より大きければ，
      //       minY = polygon[繰り返し変数].y
      maxY = polygon.p[i].y;
    }
  }

  Polygon max_min;
  max_min.p[0].x = minX;
  max_min.p[0].y = minY;
  max_min.p[1].x = maxX;
  max_min.p[1].y = maxY;
  return max_min;
}*/