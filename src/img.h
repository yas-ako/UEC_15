#define WIDTH 720
#define HEIGHT 480
#define TIME 10 * 100 //0.1秒が何回あるか
#define DELAY 5

struct color
{
  unsigned char r, g, b;
};

void img_clear(void);
void img_write(void);
void img_putpixel(struct color c, int x, int y);
void img_fillcircle(struct color c, double x, double y, double r);
void layer_1(double t);
void layer_2(double t);