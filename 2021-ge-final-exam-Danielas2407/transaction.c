
// 12S20031 - Daniel Andres Simangusnong
// 12S20054 - Rossianna Dewi Sri Hutabarat

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"

// codes
/**
 * This function creates an object of struct transaction_t.
 *
 * Parameters:
 * char*              - the transaction title,
 * unsigned short int - the transaction value,
 * enum type_t        - the transaction type.
 *
 * Returns:
 * struct transaction_t - the created object.
 */
struct transaction_t
create_transaction(char *_title, unsigned short int _amount, enum type_t _type){
    struct transaction_t tr;
        strcpy(tr.title, _title);
        tr.amount = _amount;
        tr.type = _type;
    return tr; 
}

/**
 * This function registers a transaction into the dinamic array of transactions.
 *
 * Parameters:
 * To work properly, the function requires:
 * struct transaction_t**   - the array (passed by reference) where the new
 * transaction will be registered.
 * unsigned short int       - the array length.
 * struct transaction_t     - a transaction, the to be registered transaction
 *
 * Returns:
 * short int  - the new array length.
 */
short int register_transaction(struct transaction_t **_transactions,
                               unsigned short int _transaction_size,
                               struct transaction_t _transaction){
    
    *_transactions[_transaction_size - 1] = create_transaction(_transaction.title, _transaction.amount, _transaction.type);

}

/**
 * This function calculates all the given transactions and return the balance.
 *
 * Parameters:
 * struct transaction_t*  - an array of transactions.
 * unsigned short int     - the size of the array.
 *
 * Returns:
 * short int    - the calculated balance, zero value means balanced, and beyond
 * zero means surplus.
 */
short int get_balance(struct transaction_t *_transactions,
                      unsigned short int _transaction_size);

/**
 * This function prints out transactions marked as income. The printing is done
 * in a chronological order.
 *
 * Parameters:
 * struct transaction_t*  - an array of transactions.
 * unsigned short int     - the size of the array.
 *
 * Returns:
 * void
 */
void print_income_transactions(struct transaction_t *_transactions,
                               unsigned short int _transaction_size){
    for(int i=0; i<_transaction_size; i++){
        if(_transactions[i].type == TYPE_INCOME){
            printf("%s;%d;%s\n", _transactions[i].title, _transactions[i].amount, type_to_text(_transactions[i].type));
        }
    }                               
}

/**
 * This function prints out transactions marked as expense. The printing is done
 * in a chronological order.
 *
 * Parameters:
 * struct transaction_t*  - an array of transactions.
 * unsigned short int     - the size of the array.
 *
 * Returns:
 * void
 */
void print_expence_transactions(struct transaction_t *_transactions, unsigned short int _transaction_size){
    for(int i=0; i<_transaction_size; i++){
        if(_transactions[i].type == TYPE_EXPENSE){
            printf("%s;%d;%s\n", _transactions[i].title, _transactions[i].amount, type_to_text(_transactions[i].type));
        }
    }   
}

/**
 * This function produces a line of output mentioning the balance and the
 * balance status.
 *
 * Parameters:
 * struct transaction_t*  - an array of transactions.
 * unsigned short int     - the size of the array.
 *
 * Returns:
 * void
 */
void print_summary(struct transaction_t *_transactions, unsigned short int _transaction_size){
    int total_income = 0;
    int total_expense = 0;
    for(int i=0; i<_transaction_size; i++){
        if(_transactions[i].type == TYPE_EXPENSE){
            total_expense += _transactions[i].amount;
        }else if(_transactions[i].type == TYPE_INCOME){
            total_income += _transactions[i].amount;
        }
    }  

    if(total_income > total_expense){
        printf("%d surplus\n", total_income - total_expense);
    }else if(total_income < total_expense){
        printf("%d deficit\n", total_expense - total_income);
    }else{
        printf("balanced\n");
    }
}

/**
 * This function converts a string indicating a transaction type into an
 * enumeration.
 *
 * Parameters:
 * char*  - an array of transactions.
 *
 * Returns:
 * enum type_t  - the enumeration representing the transaction type.
 */
enum type_t get_type(char *_stype){
    if(strcmp(_stype, "income") == 0){
        return TYPE_INCOME;
    }else{
        return TYPE_EXPENSE;
    }
}

/**
 * This function converts an enumeration into a string indicating a transaction
 * type.
 * Parameters:
 * enum type_t  - an enumeration of type_t.
 *
 * Returns:
 * char*  - a string, either "income" or "expense".
 */
char *type_to_text(enum type_t _type){
    switch(_type){
        case TYPE_INCOME: 
            return "income";
        case TYPE_EXPENSE:
            return "expense";
        default: 
            return "none";
    }
}