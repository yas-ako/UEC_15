/**
 * @file layer.c
 * @brief レイヤを呼び出す
 */

#include <stdio.h>
#include "img.h"

/** 現在の画像の出力枚数 */
static int i;

/** アプリケーション実行時に、ほかの関数を実行する関数 */
int main(void)
{
  for (i = 0; i < TIME / DELAY; ++i)
  {
    //画像をクリア
    img_clear();

    //レイヤごとに出力　代入している値は、動画開始からの時間(小数)
    layer_0();                    // ずっと同じ画像
    layer_1((i / 100.0) * DELAY); // レイヤ1
    layer_2((i / 100.0) * DELAY); // レイヤ2
    layer_3((i / 100.0) * DELAY); // レイヤ3
    layer_4((i / 100.0) * DELAY); // レイヤ4
    layer_5((i / 100.0) * DELAY); // レイヤ5

    // 画像を出力
    img_write();
  }

  //完了
  printf("Complete.\n");
}
