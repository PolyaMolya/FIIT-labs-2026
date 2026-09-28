/*
 *плотность в кг/м
 *расстояние между верхней и нижней крышкой и полками
 *не менее 40см
 *масса в кг
 */

#include <stdio.h>

int main()
{
  int kp = 0;
  float h, w, d, dsp, dvp, der, m;

  printf("h w d dsp dvp der\n");
  scanf("%f %f %f %f %f %f", &h, &w, &d, &dsp, &dvp, &der);

  if (h*w*d*dsp*dvp*der == 0 ||
      h<180|| h>220 || w<80 || w>120 || d<50 || d>90) 
    {printf("error\n"); return 0;}

  for (int i = 41.5; i < h-43; i+=41.5) 
    kp++;
  
  m = (dvp*h*w*0.5    + 
       2*dsp*h*d*1.5  +
       2*dsp*w*d*1.5  +
       der*h*w        +
       kp*dsp*w*d*1.5) / 1000000;

  printf("%f\n", m);

  return 0;
}
