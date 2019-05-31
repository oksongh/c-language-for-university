#include <stdio.h>

void make_upper(int width,int height,double mat[height][width]){
  /*
  for(int i = 0;i < height;i++){
    for(int j = 0;j < width;j++){
      printf("%lf ",mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  */
  for(int k = 0;k < height-1;k++){
    for(int i = k+1;i < height;i++){
      //printf("i:%d",i);
      double coeff = mat[i][k]/mat[k][k];
      //printf("coeff%lf",coeff);
      
      for(int j = k;j < width;j++){
	//printf("%lf\n",mat[i][j]);
	mat[i][j] -= coeff*mat[k][j];
      }
      
      for(int i = 0;i < height;i++){
	for(int j = 0;j < width;j++){
	  printf("%lf ",mat[i][j]);
	}
	printf("\n");
      }
      printf("\n");
    }
  }
  /*
  for(int i = 0;i < height;i++){
    for(int j = 0;j < width;j++){
      printf("%lf ",mat[i][j]);
    }
    printf("\n");
  }
  */
}
void gauss_eliminate(int width,int height,double mat[height][width],double x[height]){
  //printf("aa,width:%d,height:%d\n",width,height);
  make_upper(width,height,mat);
  double b[height];
  for(int i = 0;i < height;i++){
    b[i] = mat[i][width-1];
  }
  double A[height][height];
  for(int i = 0;i < height;i++){
    for(int j = 0;j < width-1;j++){
      A[i][j] = mat[i][j];
    }
  }
  int A_width = height;
  int A_height = height;
  x[height-1] = b[A_height-1]/A[A_height-1][A_width-1];
  
  double buf = 0;
  for(int i = A_height-2;i >= 0;i--){
    buf += b[i];
    for(int j = A_width-1;j >= 0;j--){
      buf -= A[i][j]*x[j];
    }
    x[i] = buf/A[i][i];
    buf = 0;
  }
  for(int i = 0;i < A_height;i++){
    printf("x[i] =%lf\n",x[i]);
  }

  
}
int main(){
  
  double mat[3][4] = {{2,4,6,6},
		      {3,8,7,15},
		      {5,7,21,24}};
  int height = 3;
  int width = 4;
  double x[3] = {0,0,0};
  for(int i = 0;i < height;i++){
    for(int j = 0;j < width;j++){
      printf("%lf ",mat[i][j]);
    }
    printf("\n");
  }
  gauss_eliminate(width,height,mat,x);

  return 0;
}
