#include <stdio.h>
void func(void){
  if(int b = 10){
    printf("b%d",b);
    
  }
  printf("b%d",b);
}
int main(void){
  int a;
  a = 10;
  {
    int a = 20;
    printf("a%d\n",a);
    
  }
  printf("a%d\n",a);
  /*
  if(int b = 20){
  
    printf("b%d",b);
    
  }
  printf("b%d",b);
  */
  return 0;
}
