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

void euler_method(double *y,FUNC f,double h,int n,int cond){
  if(n > cond){
    return;
  }
  y[n+1] = y[n] + h * f(y[n]);
  euler_method(y,f,h,n+1,cond);
}
void solve_func(double h,FUNC f,double init_x,double last_x,double init_y){
  int array_size = 1 + ceil((last_x - init_x) / h);
  printf("array_size:%d\n",array_size);
  double y[array_size];
  double x[array_size];
  int i;
  for(i = 0;i < array_size;i++){
    x[i] = h*i;
  }
  y[0] = init_y;
  euler_method(y,f,h,0,array_size);

  fprintf(fp,"x:");
  fprint_array(fp,array_size,x);
  fprintf(fp,"y:");
  fprint_array(fp,array_size,y);
  
  
}
int main(void){
  FUNC f;
  double h = 0;
  double init_y;
  double init_x;
  double last_x;

  if((fp = fopen("euler_method.dat","w")) == NULL){
    printf("cannot open file");
    exit(1);
  }

  f = func1;
  h = 0.1;
  init_y = 0.5;
  init_x = 0.0;
  last_x = 2.0;
  
  solve_func(h,f,init_x,last_x,init_y);

  h = 0.05;
  solve_func(h,f,init_x,last_x,init_y);

  h = 0.01;
  solve_func(h,f,init_x,last_x,init_y);

  f = func2;
  init_y = 0.5;
  h = 0.4;
  solve_func(h,f,init_x,last_x,init_y);

  h = 0.05;
  solve_func(h,f,init_x,last_x,init_y);
    
  fclose(fp);
  return 0;
}
