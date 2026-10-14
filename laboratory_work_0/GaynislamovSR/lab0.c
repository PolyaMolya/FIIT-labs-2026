#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x, y, rz2, sm2, c2;
  int x1, x2, y1, y2, r1, r2, r;

  printf("x1, y1, r1, x2, y2, r2\n");
  scanf("%i %i %i %i %i %i", &x1, &y1, &r1, &x2, &y2, &r2);


  if (r1 < 0 || r2 < 0) {printf("error: r1 or r2 < 0\n"); return 0;}

  x = abs(x1-x2);
  y = abs(y1-y2);
  c2 = x*x + y*y;
  rz2 = abs(r1-r2)*abs(r1-r2);
  sm2 = (r1+r2)*(r1+r2);


  if (c2 == 0)           printf("Центры совподают\n");
  else if (c2 < rz2)     printf("Одна внутри другой (не пересекаются)\n"); 
  else if (c2 == rz2)    printf("Внутреннее касание\n"); 
  else if (rz2 < c2 &&
           c2 < sm2)     printf("Пересекаются в 2 точках\n"); 
  else if (c2 == sm2)    printf("Внешнее касание\n");
  else if (c2 > sm2)     printf("Вне друг друга (не пересекаются)\n"); 
  
  return 0;
}
