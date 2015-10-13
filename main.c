#include <stdio.h>

int main(int argc, char *argv[]){

  char name[100];
  float amount;
  float average_payment;
  float percent;

  printf("---Loan Calc---\n");

  printf("Enter the name of the loan: ");
  scanf("%s", name);

  printf("Enter the amount on the loan: ");
  scanf("%f", amount);

  printf("Enter the apr on the loan: ");
  scanf("%f", &percent);

  printf("Enter average monthly payment: ");
  scanf("%f", &average_payment);
  
  //print out useful info
  printf("The name of the Loan is %s\n", name);
  printf("The amount on the loan is %f\n", amount);
  printf("The apr on the loan is %f\n", percent);
  printf("The average monthly payment is %f\n", average_payment);

  return 0;
}
