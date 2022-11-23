#ifndef _H_HEAD1_
#define _H_HEAD1_

#define WIDTH 720
#define HEIGHT 480
#define TIME 7 * 100 // 0.01秒が何回あるか
#define DELAY 5
#define MAX_POLYGON 10

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
void img_fillline(struct color c,double x0,double y0,double x1,double y1,double w);
void layer_1(double t);
void layer_2(double t);
void layer_3(double t);
void layer_4(double t);
void layer_5(double t);

void img_fillpolygon(struct color c, Polygon polygon);
double get_vector_length(vector v);
double dot_product(vector vl, vector vr);
double AngleOf2Vector(vector A, vector B);

int IsInPolygon(Point point, Polygon polygon);
double AngleOf3Points(Point point1, Point pont2, Point point3);
Polygon max_min_point(Polygon polygon);

#endif // _H_HEAD1_