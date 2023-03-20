
#include <stdio.h>
#include <stdlib.h>

int main(int _argv, char **_argc) {
short int *i = NULL;
short int *j = NULL;

i = calloc(2, sizeof(short int));
i = malloc(sizeof(short int) * 1);

printf("&d, %d\n", *i, *(j+1));
free(i);
free(j);


return 0;
}