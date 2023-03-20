// DO NOT EDIT
#include "transaction.h"

#ifndef REPOSITORY_H
#define REPOSITORY_H

/**
 * The location of the transaction repository.
 */
#define DEFAULT_TRANSACTION_REPOSITORY "./storage/transaction-repository.txt"

/**
 * This function loads all persisted transcations stored in the repository.
 *
 * Parameters:
 * struct transaction_t**   - an array into which the persisted transactions are
 * going to be loaded.
 *
 * Returns:
 * short int    - the number of loaded transactions.
 */
short int
load_transactions_from_repository(struct transaction_t **_transactions);

/**
 * This function stores all transcations in the program into the persistent
 * storage.
 *
 * Parameters:
 * struct transaction_t*  - an array of transactions.
 * unsigned short int     - the size of the array.
 *
 * Returns:
 * void.
 */
void save_transactions_to_repository(struct transaction_t *_transactions,
                                     unsigned short int _transaction_size);

#endif
// DO NOT EDIT
