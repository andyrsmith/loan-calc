#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Loan {
  char *name;
  float amount;
  float interest_rate;
  float average_payment;
  float monthly_interest;
  float total_interest;
  int month;
  float monthly_interest_rate;
};

struct Loan *Create_loan(){
  char name[100];
  float amount;
  float interest_rate;
  float average_payment;

  printf("Enter the name of the loan: ");
  scanf("%s", name);

  printf("Enter the amount on the loan: ");
  scanf("%f", &amount);

  printf("Enter the apr on the loan: ");
  scanf("%f", &interest_rate);

  printf("Enter average monthly payment: ");
  scanf("%f", &average_payment);

  struct Loan *new = malloc(sizeof(struct Loan));
  assert(new != NULL);

  new->name = strdup(name);
  new->amount = amount;
  new->interest_rate = interest_rate;
  new->average_payment = average_payment;

  return new;
}

void calc_future_interest(struct Loan *new_loan) {
  float new_total;
  new_loan->month = 1;
  new_loan->monthly_interest_rate = new_loan->interest_rate / 12;

  while( new_loan->amount > 0.00 ) {
    new_loan->monthly_interest = new_loan->amount * new_loan->monthly_interest_rate;
    new_total = new_loan->monthly_interest + new_loan->amount;
    new_loan->total_interest = new_loan->total_interest + new_loan->monthly_interest;
    new_loan->amount = new_total - new_loan->average_payment;
    new_loan->month++;
  }
}

int main(int argc, char *argv[]){


  printf("---Loan Calc---\n");
  struct Loan *new_loan = Create_loan();

  calc_future_interest(new_loan); 

  printf("-----------------------------\n");
  printf("The monthly interest is: %.2f\n", new_loan->monthly_interest_rate);

  
  printf("It would take you %i of months to pay off loan\n", new_loan->month); 
  printf("The total interest would be %.2f\n", new_loan->total_interest);

  return 0;
}
