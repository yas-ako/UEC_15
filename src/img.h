#ifndef _H_HEAD1_
#define _H_HEAD1_

/** @def
 * 画面横幅
 */
#define WIDTH 720

/** @def
 * 画面縦幅
 */
#define HEIGHT 480

/** @def
 * 0.01秒が何回あるか
 */
#define TIME 15 * 100

/** @def
 * １コマ当たりの時間
 */
#define DELAY 5

/** @def
 * ポリゴンの最大長点数
 */
#define MAX_POLYGON 20

struct color
{
  unsigned char r, g, b;
};

typedef struct
{
  double x;
  double y;
} vector;

typedef struct
{
  double x;
  double y;
} Point;

typedef struct
{
  Point p[MAX_POLYGON];
  int n;
} Polygon;

void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);
void img_fillcircle(struct color c, double x, double y, double r);
void img_filltriangle(struct color c, double x0, double y0, double z0, double f0, double x1, double y1, double z1, double f1, double x2, double y2, double z2, double f2);
void img_fillline(struct color c, double x0, double y0, double x1, double y1, double w);
void layer_0(void);
void layer_1(double t);
void layer_2(double t);
void layer_3(double t);
void layer_4(double t);
void layer_5(double t);

void img_fillpolygon(struct color c, Polygon polygon);
int IsInPolygon(Point point, Polygon polygon);

void img_fillrect(struct color c, double x, double y, double w, double h);

#endif // _H_HEAD1_
