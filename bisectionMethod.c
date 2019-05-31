#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func0(double x){
  return x*x*x - 3*x + sin(x);
}

double func1(double x){
  return 3/x - sin(x)/(x*x);
}

double func2(double x){
  return (1/3)*(x*x*x + sin(x));
}

  
int main(void){
  double left = 1;
  double right = 2;
  double center,fl,fr,fc;
  double thresh_value = 0.0001;
  int i;
  for(i = 0;right - left > thresh_value;i++){
    
    center = (left+right)/2;    
    //printf("aaa%f \n",func(left));
    fc = func0(left);
    if(func0(left)*func0(center) > 0){
      left = center;
      //b = b;
    }else{
      right = center;
      //a = a;
    }
    printf("center %f \n",center);
  }
  return 0;
}
