#include <stdio.h>
#include <stdlib.h>
#include "..\img.h"
#include "img.h"


int main(void) {
  struct color c1={0,0,255};
  struct color c2={255,255,255};

  int i;
  for(i=0;i<20;++i) {
    img.clear();
   img_filltriangle(c1,120+i*8,180,20+i*8,20,140+i*8,180,120+i*8,180,240+i*8,20,240+i*8,20);
   img_filltriangle(c2,120+i*8,180,100+i*8,160,140+i*8,180,120+i*8,180,160+i*8,160,160+i*8,160);
   img_write();
  }
}