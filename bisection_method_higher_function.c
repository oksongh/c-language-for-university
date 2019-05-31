#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef double (* FUNC)(double);

double func0(double x){
  return x*x*x - 3*x + sin(x);
}

double func1(double x){
  return 3/x - sin(x)/(x*x);
}

double func2(double x){
  return (1/3)*(x*x*x + sin(x));
}

double bisection_method(FUNC func,double left,double right,double thresh_value){
  // (* func)(x);
  double center;
  double fc,fl,fr;
  if(func(left)*func(right) > 0){
    printf("errer:not found answer by range or function shape\n");
    return 0;
  }
  int i;
  for(i = 0;right - left > thresh_value;i++){
    fl = func(left);
    fr = func(right);
    center = (left+right)/2;    
    //printf("aaa%f \n",func(left));
    fc = func(center);
    
    if(func(left)*func(center) > 0){
      left = center;
      //b = b;
    }else{
      right = center;
      //a = a;
    }
    printf("center %f \n",center);
  }
  return center;

}
  
int main(int argc,char **argv){
  double left = 1;
  double right = 2;
  double fl = 0;
  double fc = 0;
  double center;
  //  char ch = thresh[0];
  double thresh_value = atof(argc[1]);
  int i = atoi(argc[2]);
  
  double (*func[])() = {func0,func1,func2};
  printf("th %f \n",thresh_value);
  bisection_method(func[i],left,right,thresh_value);
  
}
