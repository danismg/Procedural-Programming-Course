// 12S20031 - Daniel Andres Simangusnong
// 12S20054 - Rossianna Dewi Sri Hutabarat

#include "custom.h"
#include "repository.h"
#include "transaction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv) {
  // codes
  const int MAX_LINES = 250;
  char lines[MAX_LINES];
  char* token;

  unsigned short int n_transactions = 0;
  struct transaction_t *transactions = malloc((n_transactions + 1) * sizeof(struct transaction_t)); // size = 1
  struct transaction_t tmp_transaction; 


  while(1==1){

    get_string(lines, MAX_LINES);

    if(strcmp(lines, "---") == 0){
      break;
    }
    else if(strcmp(lines, "print-income-transactions") == 0){
      print_income_transactions(transactions, n_transactions);
    }
    else if(strcmp(lines, "print-expense-transactions") == 0){
      print_expence_transactions(transactions, n_transactions);
    }
    else if(strcmp(lines, "print-summary") == 0){
      print_summary(transactions, n_transactions);
    }
    
    else{ 

      token = strtok(lines, "#");
      if(strcmp(token, "register-transaction") == 0){
        token = strtok(NULL, "#"); // ambil type
        tmp_transaction.type = get_type(token);
         token = strtok(NULL, "#"); // ambil amount
        tmp_transaction.amount = atoi(token);
        token = strtok(NULL, "#"); // ambil title
        strcpy(tmp_transaction.title, token); 
       
        // register_transaction(&transactions, n_transactions, tmp_transaction);
        n_transactions += 1;
        transactions[n_transactions-1] = create_transaction(tmp_transaction.title, tmp_transaction.amount, tmp_transaction.type);
        transactions = realloc(transactions, (n_transactions + 1) * sizeof(struct transaction_t));
      }

    }


  }



  return 0;
}