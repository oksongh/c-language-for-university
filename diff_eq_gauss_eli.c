#include <stdio.h>

void print_vec(const int length,const double vec[length]){
  int i;
  for(i = 0;i < length;i++){
    printf("%lf \n",vec[i]);
    
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

void make_upper(const int height,const int width,double mat[height][width]){
  int i,j,k;

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
int main(){
    
  const int split = 10;
  
  const int height = split - 1;
  const int width = height;
  const double h = 3.0 / split;
  //const x_len = split + 1;
  
  double x[split + 1];
  double mat[height][height];
  double ans[split - 1];
  double vecb[height];
  //B.C.
  x[0] = 0;
  x[split] = 1.0;
  //  double ans0 = 0;
  //  double ans1 = 0;

  int i,j;
  
  for(i = 1;i < split;i++){
   
    x[i] = (double)i/split;
  }
  printf("x:");
  print_vec(split+1,x);
  for(i = 0;i < height;i++){
    vecb[i] = -2.0*h*h*x[i+1];
  }
  printf("vecb:");
  print_vec(height,vecb);
  for(i = 0;i < height;i++){
    for(j = 0;j < width; j++){
      if(i == j){
	mat[i][j] = -4;
      }else if(i == j + 1){
	mat[i][j] = 2 + h;
      }else if(i == j - 1){
	mat[i][j] = 2 - h;	
      }else{
	mat[i][j] = 0;
      }
    }
  }
  
  print_mat(height,width,mat);
  gauss_eliminate(height,mat,vecb,ans);

  return 0;
}
