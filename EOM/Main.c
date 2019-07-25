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

void euler_method(double *x,double *v,double h,int n,int cond){
  if(n >= cond){
    return;
  }
  
  printf("n %d ",n);
  printf("xn %lf ",x[n]);
  printf("vn %lf\n",v[n]);
  
  x[n+1] = x[n] + h * v[n];
  v[n+1] = v[n] - h * x[n];
  euler_method(x,v,h,n+1,cond);
}
/*void runge_kutta_method(double* y,const FUNC f,const double h,const int ksize,int n,const int cond){
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
  
  
  }*/
void solve_func(double h,double init_t,double last_t,double init_x,double init_v){
  int array_size = 1 + ceil((last_t - init_t) / h);
  printf("array_size:%d\n",array_size);
  double x[array_size];
  double v[array_size];
  double t[array_size];
  
  int i;
  for(i = 0;i < array_size;i++){
    t[i] = h*i;
  }
  v[0] = init_v;
  x[0] = init_x;
  
  euler_method(x,v,h,0,array_size);
  
  
  fprintf(fp,"\n");
  fprintf(fp,"t:");
  fprint_array(fp,array_size,t);
  
  fprintf(fp,"x:");
  fprint_array(fp,array_size,x);
  
  fprintf(fp,"v:");
  fprint_array(fp,array_size,v);
  fprintf(fp,"\n");
  
}

int main(void){
  FUNC f;
  double h = 0;
  double init_x;
  double init_v;
  double init_t;
  double last_t;

  if((fp = fopen("EOM.dat","w")) == NULL){
    printf("cannot open file");
    exit(1);
  }

  f = func1;
  h = 0.1;
  
  init_t = 0.0;
  last_t = 20.0;

  init_x = 1.0;
  init_v = 0.0;
  
  solve_func(h,init_t,last_t,init_x,init_v);
 
  fclose(fp);
  return 0;
}
