#include <stdio.h>

int main(int argc, char *argv[]){

  char name[100];
  float amount;
  float average_payment;
  float interest_rate;
  float monthly_interest_rate;
  float monthly_interest;
  float new_total;
  int month = 0;
  float total_interest = 0.00;

  printf("---Loan Calc---\n");

  printf("Enter the name of the loan: ");
  scanf("%s", name);

  printf("Enter the amount on the loan: ");
  scanf("%f", &amount);

  printf("Enter the apr on the loan: ");
  scanf("%f", &interest_rate);

  printf("Enter average monthly payment: ");
  scanf("%f", &average_payment);
  
  monthly_interest_rate = interest_rate / 12;
  printf("-----------------------------\n");
  printf("The monthly interest is: %.2f\n", monthly_interest_rate);

  while( amount > 0.00 ) {
    monthly_interest = amount * monthly_interest_rate;
    new_total = monthly_interest + amount;
    total_interest = total_interest + monthly_interest;
    amount = new_total - average_payment;
    month++;
  }
  
  printf("It would take you %i of months to pay off loan\n", month); 
  printf("The total interest would be %.2f\n", total_interest);

  return 0;
}
