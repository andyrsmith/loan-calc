#include <stdio.h>

int main(int argc, char *argv[]){

  char name[100];
  int amount;

  printf("---Loan Calc---\n");

  printf("Enter the name of the loan: ");
  fgets(name, 100, stdin);

  printf("Enter the amount on the loan: ");
  fscan(stdin, "%i", amount);

  return 0;
}
