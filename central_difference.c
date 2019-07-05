#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double (* FUNC)(double);
typedef double (* METHOD)(FUNC,double,double);

double central_difference(FUNC f,double arg_x,double h){
  return (f(arg_x + h)-f(arg_x - h))/(2*h);
}
double advance_difference(FUNC f,double arg_x,double h){
  return (f(arg_x + h) - f(arg_x))/h;
}
double backward_diffence(FUNC f,double arg_x,double h){
  return (f(arg_x) - f(arg_x - h))/h;
}

int main(){
  FUNC f = exp;
  double true_value_arg = 1.0;
  double true_value = f(true_value_arg);
  METHOD methods[] = {central_difference,advance_difference,backward_diffence};
  double errs[3];
  
  printf("f(x) %lf\n",f(true_value_arg));

  FILE *fp;
  if((fp = fopen("difference_output.dat","w")) == NULL){
    printf("cannot open file");
    exit(1);
  }
  fprintf(fp,"h \t central \t advance \t backward\n");
  
  double h_diff;
  int i,k;
  for(i = 0;i < 50;i++){
    h_diff = 1/pow(2,i);
    for(k = 0;k < 3;k++){
      errs[k] = fabs(methods[k](f,true_value_arg,h_diff) - true_value);

    }
    printf("h:%lf %.10lf %.10lf %.10lf \n",h_diff,errs[0],errs[1],errs[2]);
    
    fprintf(fp,"%le \t %.10le \t %.10le \t %.10le \n",h_diff,errs[0],errs[1],errs[2]);
  }
  fclose(fp);
  return 0;
}
