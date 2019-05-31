#include <stdio.h>
#include <math.h>

typedef double (* FUNC)(double);
double esp = 0.0001;
double h = 0.000001;

double differentation(FUNC f,double x){
  return (f(x+h)-f(x))/h;
}

double func0(double x){
  return x*x*x - 3*x + sin(x);
}

double newton_method(double xi,FUNC func){
  double fi = func(xi);
  double f_prime_i = differentation(func,xi);
  double x_next = xi - fi/f_prime_i;

  printf("fi = %f,f_prime_i = %f,xi+1 = %f \n",fi,f_prime_i,x_next);
  
  if(fabs(xi - x_next) > esp){
    newton_method(x_next,func);
  }else{
    return x_next;
  }
  
}
int main(int arg,char **argv){
  double x0 = 1.0;
  
  printf("answer %f\n",newton_method(x0,func0));
  return 0;

}
