// M_Pi
#include "s21_math.h"
#define SIZE 9 
long double arctan(double x);

int main() {
  double test[SIZE];
  test[0]=-1000;
  test[1]=-5.638;
  test[2]=-1;
  test[3]=-0.39;
  test[4]=0;
  test[5]=1000;
  test[6]=5.638;
  test[7]=1;
  test[8]=0.39;

  var variables = {0};
  variables.x=1;
  for (int i=0;i<SIZE;i++){
    variables.x=test[i];
  printf("mine %lf: %Lf\n",test[i],arctan(variables.x));
  printf("original %lf: %f\n\n",test[i],atan(variables.x));
  }
  printf("asin %lf: %f\n",1000.1,asin(1000));
  return 0;
}
long double arctan(double x) {
  long double resSum=0;
if ((x > -1) && (x<1)){
 for (int i=0;i<500;i++){
  resSum+=pow(-1,i)*pow(x,(1+2*i))/(1+2*i);
 }
}
if ((x < -1) || (x>1)){
 for (int i=0;i<500;i++){
resSum+=pow(-1,i)*pow(x,(-1-2*i))/(1+2*i);
 }
 resSum=M_PI*sqrt(x*x)/(2*x) - resSum;
}
if ((x) == (-1)){
resSum=-M_PI/4;
}
if ((x) == 1){
resSum=M_PI/4;
}
return(resSum);
}

long double arctan(double x){

}