// DO NOT EDIT
#ifndef TRANSACTION_H
#define TRANSACTION_H

/**
 * An enumeration used for describing the type of a transaction.
 * There are two posibilities, income and expense.
 */
enum type_t { TYPE_INCOME, TYPE_EXPENSE };

/**
 * A structure that encapsulates a transaction. It has three attributes:
 * char[21]           - the transaction title (20 characters),
 * unsigned short int - the transaction value (whole number),
 * enum type_t        - the type of the transaction (see the type_t).
 */
struct transaction_t {
  char title[21];
  unsigned short int amount;
  enum type_t type;
};

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
create_transaction(char *_title, unsigned short int _amount, enum type_t _type);

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
                               struct transaction_t _transaction);

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
                               unsigned short int _transaction_size);

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
void print_expence_transactions(struct transaction_t *_transactions,
                                unsigned short int _transaction_size);

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
void print_summary(struct transaction_t *_transactions,
                   unsigned short int _transaction_size);

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
enum type_t get_type(char *_stype);

/**
 * This function converts an enumeration into a string indicating a transaction
 * type.
 * Parameters:
 * enum type_t  - an enumeration of type_t.
 *
 * Returns:
 * char*  - a string, either "income" or "expense".
 */
char *type_to_text(enum type_t _type);

#endif
// DO NOT EDIT
