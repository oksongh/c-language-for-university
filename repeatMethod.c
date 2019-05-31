#include <stdio.h>
#include <math.h>

double func(double x);

int main(void){
  double x,ansabs,ans;
  x = 2.0;
  ansabs = 1e5;
  int i = 0;
  for(i = 0; ansabs > 1e-7;i++){
    ans = func(x);
    ansabs = fabs(x - ans);
    printf("i:%d,ans:%f",i,ans);
    printf("ansabs%f \n",ansabs);
    x = ans;
  }
}

double func(double x){
  return pow(3*x-sin(x),1.0/3.0);
}
