#include <stdio.h>
#include <math.h>
#include <stdlib.h>

FILE *fp;
typedef double (* FUNC)(double);

double func1(double x){
  return x*x;
}

double func2(double x){
  return -3*x;
}
double func3(double x){
  return 1 - x;
}
void print_array(int size,double *array){
  int i;
  for(i = 0;i < size;i++){
    printf("%lf\n",array[i]);
  }
  printf("\n");
}
void fprint_array(FILE* fp,int size,double *array){
  int i;
  for(i = 0;i < size;i++){
    fprintf(fp,"%lf ",array[i]);
  }
  fprintf(fp,"\n");
}

void euler_method(double *y,FUNC f,double h,int n,int cond){
  if(n > cond){
    return;
  }
  y[n+1] = y[n] + h * f(y[n]);
  euler_method(y,f,h,n+1,cond);
}
void runge_kutta_method(double* y,const FUNC f,const double h,const int ksize,int n,const int cond){
  if(n > cond){
    return;
  }
  double k[ksize];
  int i;
  k[0] = h*f(y[n]);
  for(i = 1;i < ksize - 1;i++){
    k[i] = h * f(y[n] + 0.5 * k[i-1]);
    
  }
  k[ksize - 1] = h * f(y[n] + k[ksize - 2]);
  double sum = k[0] + k[ksize - 1];
  for(i = 1;i < ksize - 1;i++){
    sum += 2 * k[i];
  }
  printf("sum %lf %d\n",sum,2 + (ksize - 2)*2);

  y[n+1] = y[n] + sum/(2 + (ksize - 2)*2);
  runge_kutta_method(y,f,h,ksize,n + 1,cond);
  
  
}
void solve_func(double h,FUNC f,double init_x,double last_x,double init_y,int runge_size){
  int array_size = 1 + ceil((last_x - init_x) / h);
  printf("array_size:%d\n",array_size);
  double y[array_size];
  double x[array_size];
  int i;
  for(i = 0;i < array_size;i++){
    x[i] = h*i;
  }
  y[0] = init_y;
  switch (runge_size){
  case 1:
    euler_method(y,f,h,0,array_size);
    break;
  case 2:
    runge_kutta_method(y,f,h,2,0,array_size);
    break;
  default:
    runge_kutta_method(y,f,h,runge_size,0,array_size);
    break;
  }
  

  fprintf(fp,"\n");
  fprintf(fp,"x:");
  fprint_array(fp,array_size,x);
  fprintf(fp,"y:");
  fprint_array(fp,array_size,y);
  fprintf(fp,"\n");
  
}

int main(void){
  FUNC f;
  double h = 0;
  double init_y;
  double init_x;
  double last_x;

  if((fp = fopen("rc_circuit.dat","w")) == NULL){
    printf("cannot open file");
    exit(1);
  }

  f = func3;
  h = 0.05;
  init_y = 0.0;
  init_x = 0.0;
  last_x = 20.0;
  
  solve_func(h,f,init_x,last_x,init_y,1);
  solve_func(h,f,init_x,last_x,init_y,2);
  solve_func(h,f,init_x,last_x,init_y,4);
  fclose(fp);
  return 0;
}
