//081860061 奥村匡紀
#include <stdio.h>

#define N 3
/*
typedef struct {
  int linelen;
  int rowlen;
  double **mat;
} Matrix;
*/
void turn_mat(double mat[N][N]){
  
}
void inner_product_matvec(double mat[N][N],double invec[N],double outvec[N]){
  int i,j;
  for(j = 0;j < N;j++){
    for(i = 0;i < N;i++){
      outvec[j] += mat[j][i]*invec[i];
      
    }
  }
  
}
void inner_product_matmat(double mat0[N][N],double mat1[N][N],double outmat[N][N]){
  int i,j,k;
  for(k = 0;k < N;k++){
    for(i = 0;i < N;i++){
      for(j = 0;j < N;j++){
	outmat[i][k] += mat0[i][j]*mat1[j][k];
      }
    }
  }
}

int main(void){
  int i,j;
  double A[N][N] = {{1.0,3.0,2.0},{9.0,1.0,8.0},{-1.0,-5.0,-3.0}};
  double b[N] = {1.0,2.0,3.0};
  double x[N];
  inner_product_matvec(A,b,x);
  printf("Ab=");
  for(i = 0;i < N;i++){
    printf("%f ",x[i]);
  }
  printf("\n\n");
  
  double Aa[N][N] = {{1.0,2.0,3.0},
		     {2.0,5.0,7.0},
		     {3.0,7.0,4.0}};
  double B[N][N] = {{2.0,0.0,1.0},
		    {0.0,3.0,2.0},
		    {1.0,2.0,3.0}};
  double C[N][N];
  inner_product_matmat(Aa,B,C);

  printf("AB=");
  for(i = 0;i < N;i++){
    for(j = 0;j < N;j++){
      printf("%f ",C[i][j]);
    }
    printf("\n");
  }
  /*
  double mat[N][N] = {{1,3,2},{9,1,8},{-1,-5,-3}};
  double b[] = {1,2,-1};
  double c[N];
  printf("c");
  for(int i = 0;i < N;i++){
    c[i] = 0;
    for(int j = 0;j < N;j++){
      c[i] += mat[i][j]*b[j];
    }
    printf(" %f \n",c[i]);
  }
  */
  
  return 0;
}
