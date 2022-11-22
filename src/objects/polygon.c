#define _USE_MATH_DEFINES
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

//ベクトルの長さを計算する
double get_vector_length(vector v)
{
  return pow((v.x * v.x) + (v.y * v.y), 0.5);
}

//ベクトル内積
double dot_product(vector vl, vector vr)
{
  return vl.x * vr.x + vl.y * vr.y;
}

//２つのベクトルABのなす角度θを求める
double AngleOf2Vector(vector A, vector B)
{
  //ベクトルAとBの長さを計算する
  double length_A = get_vector_length(A);
  double length_B = get_vector_length(B);

  //内積とベクトル長さを使ってcosθを求める
  double cos_sita = dot_product(A, B) / (length_A * length_B);

  // cosθからθを求める
  double sita = acos(cos_sita);

  //ラジアンでなく0～180の角度でほしい場合はコメント外す
  sita = sita * 180.0 / M_PI;

  return sita;
}

int IsInPolygon(Point point, Polygon polygon)
{
  double degree = 0; //角度の合計を入れる変数を定義
  Point p1;
  Point p2;
  //一つ目の点のデータを展開
  p1.x = point.x;
  p1.y = point.y;
  for (int i = 0; i < polygon.n; i++)
  {
    //  二つ目の点を取得
    
    //    if 二つ目の点の次があるのなら，
    //      三つ目の点のデータを取得
    //    else なければ，
    //      一番最初の値を取得
    //    end 終わり
    //  点のデータをAngleOf3Points()に入れて，戻戻り値を取得
    //  角度を足す
    // end
  }

  // if 角度の合計が，0.01以下である
  //   0
  // else
  //   1
}

//多角形の隣り合った2点と，調べたい点のなす角を求める
double AngleOf3Points(Point point1, Point pont2, Point point3)
{
  //ベクトルOAを求める
  //ベクトルOBを求める．
  //  AngleOf2Vector()に代入
  //上の値を返却
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
  }
  Polygon max_min;
  max_min.p[0].x = minX;
  max_min.p[0].y = minY;
  max_min.p[1].x = maxX;
  max_min.p[1].y = maxY;
  return max_min;
}