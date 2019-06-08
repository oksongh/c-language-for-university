#include <stdio.h>
#define N 3

void print_vec(const int length,double vec[length]){
  int i;
  for(i = 0;i < length;i++){
    printf("%lf ",vec[i]);
    
  }
  printf("\n");
}
void print_mat(const int height,const int width,const double mat[height][width]) {
  int i,j;
  for(i = 0;i < height;i++){
    for(j = 0;j < width;j++){
      printf("%lf ",mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void identity_mat(const int height,double matI[height][height]){
  int i,j;
  for(i = 0;i < height;i++){
    for(j = 0;j < height;j++){
      matI[i][j] = (i==j)?1:0;
    }

  }
}
void get_turn(const int height,const int width,const double mat[height][width],double t_mat[width][height]){
  int i,j;
  for(i = 0;i < height;i++){
    for(j = 0;j < width;j++){
      t_mat[j][i] = mat[i][j];
    }
  }
    
}
void make_upper(const int height,const int width,double mat[height][width]){
  int i,j,k,l;

  for(k = 0;k < height-1;k++){

    for(i = k+1;i < height;i++){

      double coeff = mat[i][k]/mat[k][k];


      for(j = k;j < width;j++){

	mat[i][j] -= coeff*mat[k][j];

      }
      
      //print_mat(height,width,mat);
     
    }
    
  }
  printf("made upper\n");
  print_mat(height,width,mat);
  
}
void gauss_eliminate(const int A_height,const double matA[A_height][A_height],const double vecb[A_height],double x[A_height]){
  //printf("aa,width:%d,height:%d\n",width,height);
  int i,j,k;
  int A_width = A_height;

  double mat[A_height][A_width+1];
  for(i = 0;i < A_height;i++){
    for(j = 0;j < A_width;j++){
      mat[i][j] = matA[i][j];
    }

    mat[i][A_width] = vecb[i];
  }
  //print_mat(A_height,A_width,mat);
  
  make_upper(A_height,A_width+1,mat);
  
  double Aprime[A_height][A_width];
  double bprime[A_height];

  for(i = 0;i < A_height+1;i++){
    for(j = 0;j < A_width;j++){
      Aprime[i][j] = mat[i][j];
    }
    bprime[i] = mat[i][A_width];
  }
  
  double buf = 0;

  for(i = A_height-1;i >= 0;i--){
    buf += bprime[i];
    for(j = A_width-1;i != A_height-1 && j >= 0;j--){
      buf -= Aprime[i][j]*x[j];
    }
    x[i] = buf/Aprime[i][i];
    buf = 0;
      
  }
  printf("get solution\n");
  print_vec(A_height,x);
  
}

void get_inv_mat(const int height,const double A[height][height],double inv_A[height][height]){
  int i;
  double I[height][height];
  double buf[height][height];
  identity_mat(height,I);
  //identity need no turn
  for(i = 0;i < height;i++){
    gauss_eliminate(height,A,I[i],buf[i]);
  }
  get_turn(height,height,buf,inv_A);
  
  
}
int main(void){

  double A[N][N] = {{2,4,6},
		    {3,8,7},
		    {5,7,21}};
  
  int height = N;
  double inv_A[height][height];

  get_inv_mat(height,A,inv_A);

  printf("get inverse matrix\n");
  print_mat(height,height,inv_A);
  return 0;
}
