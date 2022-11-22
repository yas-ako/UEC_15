#include <stdio.h>

void num_arr2(int numline, int numlen, int num[numline][numlen])
{
  for (int i = 0; i < numline; i++)
  {
    for (int j = 0; j < numlen; j++)
    {
      printf("%d ", num[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int num[][2] = {{32, 4}, {74, 5}, {56, 13}, {70, 56}, {32, 85}, {16, 24}, {75, 35}, {69, 41}, {5, 5}};
  int numlen = 2;
  int numline = sizeof(num) / sizeof(int) / numlen;
  num_arr2(numline, numlen, num);

  return 0;
}