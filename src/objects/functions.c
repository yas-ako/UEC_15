#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"
#include <math.h>

void img_fillcircle(struct color c, double x, double y, double r)
{
  int imin = (int)(x - r - 1), imax = (int)(x + r + 1);
  int jmin = (int)(y - r - 1), jmax = (int)(y + r + 1);
  int i, j;
  for (j = jmin; j <= jmax; ++j)
  {
    for (i = imin; i <= imax; ++i)
    {
      if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r)
      {
        img_putpixel(c, i, j);
      }
    }
  }
}

/**
 * @fn
 * 多角形を描画
 * @param (c) 色
 * @param (polygon) 多角形のデータ
 * @sa IsInPolygon
 */
void img_fillpolygon(struct color c, Polygon polygon)
{
  int minX = 0;      // 最小値X座標
  int minY = 0;      // 最小値Y座標
  int maxX = WIDTH;  // 最大値X座標
  int maxY = HEIGHT; // 最大値Y座標

  for (int j = minY; j <= maxY; ++j)
  {
    for (int i = minX; i <= maxX; ++i)
    {
      Point p;
      p.x = i;
      p.y = j;

      if (IsInPolygon(p, polygon) == 1) // 点が多角形の中にあるかどうか
      {
        // あったら、点を描く
        img_putpixel(c, i, j);
      }
    }
  }
}

static double oprod(double a, double b, double c, double d)
{
  return a * d - b * c;
}

static int isinside(double x, double y, int n, double ax[], double ay[])
{
  int i;
  for (i = 0; i < n; ++i)
  {
    if (oprod(ax[i + 1] - ax[i], ay[i + 1] - ay[i], x - ax[i], y - ay[i]) < 0)
    {
      return 0;
    }
  }
  return 1;
}

static double amax(int n, double a[])
{
  double m = a[0];
  int i;
  for (i = 0; i < n; ++i)
  {
    if (m < a[i])
    {
      m = a[i];
    }
  }
  return m;
}

static double amin(int n, double a[])
{
  double m = a[0];
  int i;
  for (i = 0; i < n; ++i)
  {
    if (m > a[i])
    {
      m = a[i];
    }
  }
  return m;
}

void img_fillconvex(struct color c, int n, double ax[], double ay[])
{
  int xmax = (int)(amax(n, ax) + 1), xmin = (int)(amin(n, ax) - 1);
  int ymax = (int)(amax(n, ay) + 1), ymin = (int)(amin(n, ay) - 1);
  int i, j;
  for (i = xmin; i <= xmax; ++i)
  {
    for (j = ymin; j <= ymax; ++j)
    {
      if (isinside(i, j, n, ax, ay))
      {
        img_putpixel(c, i, j);
      }
    }
  }
}

void img_filltriangle(struct color c, double x0, double y0, double z0, double f0, double x1, double y1, double z1, double f1, double x2, double y2, double z2, double f2)
{
  double ax1[] = {x0, x1, x2, x0}, ax2[] = {x0, x2, x1, x0};
  double ay1[] = {y0, y1, y2, y0}, ay2[] = {y0, y2, y1, y0};
  double az1[] = {z0, z1, z2, z0}, az2[] = {z0, z2, z1, z0};
  double af1[] = {f0, f1, f2, f0}, af2[] = {f0, f2, f1, f0};
  img_fillconvex(c, 3, ax1, ay1);
  img_fillconvex(c, 3, ax2, ay2);
  img_fillconvex(c, 3, az1, af1);
  img_fillconvex(c, 3, az2, af2);
}

void img_fillline(struct color c, double x0, double y0, double x1, double y1, double w)
{
  double dx = y1 - y0, dy = x0 - x1, n = 0.5 * w / sqrt(dx * dx + dy * dy);
  dx *= n;
  dy *= n;
  double ax[] = {x0 - dx, x0 + dx, x1 + dx, x1 - dx, x0 - dx};
  double ay[] = {y0 - dy, y0 + dy, y1 + dy, y1 - dy, y0 - dy};
  img_fillconvex(c, 4, ax, ay);
}
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
