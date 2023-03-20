// 12S20031 - Daniel Andres Simangusnong
// 12S20054 - Rossianna Dewi Sri Hutabarat


#include "repository.h"
#include "custom.h"
#include "transaction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// codes
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
load_transactions_from_repository(struct transaction_t **_transactions){
    return 0;
}

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
                                     unsigned short int _transaction_size){
    FILE *fp;
    fp = fopen(DEFAULT_TRANSACTION_REPOSITORY, "a");
    char data[150];
    for(int i=0; i<_transaction_size; i++){
        fprintf(fp, "%s|%d|%s", _transactions[i].title, _transactions[i].amount, type_to_text(_transactions[i].type));
    }
    fclose(fp);
}
