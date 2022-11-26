/**
 * @file polygon.c
 * @brief 多角形を出力する関数を定義
 */

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "..\img.h"

int IsInPolygon(Point point, Polygon polygon)
{
  double degree = 0; // 角度の合計を入れる変数を定義
  Point p1;          // 調べる点
  Point p2;          // 多角形の頂点１
  Point p3;          // 多角形の頂点２

  // 調べる点のデータを展開
  p1.x = point.x;
  p1.y = point.y;
  for (int i = 0; i < polygon.n; i++)
  {
    // 多角形の頂点１を取得
    p2.x = polygon.p[i].x;
    p2.y = polygon.p[i].y;

    // 「多角形の頂点１」に次がないかどうか
    if (i + 1 == polygon.n)
    {
      // 一番最初の点を「多角形の頂点２」として取得
      p3.x = polygon.p[0].x;
      p3.y = polygon.p[0].y;
    }
    else
    {
      // 次の点を「多角形の頂点２」として取得
      p3.x = polygon.p[i + 1].x;
      p3.y = polygon.p[i + 1].y;
    }

    // ベクトルの成分を計算
    double ax = p2.x - p1.x;
    double ay = p2.y - p1.y;
    double bx = p3.x - p1.x;
    double by = p3.y - p1.y;

    // 内積の定義からコサインを計算
    double cosine = (ax * bx + ay * by) / (sqrt(ax * ax + ay * ay) * sqrt(bx * bx + by * by));

    // コサインを弧度法から度数法に変換
    cosine = acos(cosine) * 180.0 / M_PI;

    // 外積を計算
    double g = ax * by - ay * bx;

    // 外積の符号をコサインにコピーし、足し合わせる
    degree += copysign(cosine, g);
  } // 繰り返し終わり

  // 角度の合計の絶対値が，0.01以上かどうか
  if (fabs(degree) >= 0.01)
  {
    // 0.01以上であれば、多角形の中
    return 1;
  }

  // 0.01未満であれば、多角形の外
  return 0;
}
