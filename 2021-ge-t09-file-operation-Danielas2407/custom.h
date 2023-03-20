#include <stdio.h>
#include <string.h>

struct Student {
  char nama[255];
  char nim[9];
  char angkatan[5];
  char sex[7];
};

int main ( int _argv, char **_argc )
{
  char order[10];
  char line[10][255];
  struct Student students[10];
  int i=0;
  int keepGoing = 1;
  char *token;
  char delim[2] = "|";
  scanf("%[^\n]s", order);
  if ( strcmp(order, "register") == 0 ) {
    while ( keepGoing == 1 ) {
        // scanf("%[^\n]s",line[i]);
        fgets(line[i],255,stdin);
        if (strcmp(line[i],"---")==0) keepGoing = 0;
        else i++;
    }
    for ( int o=0; o<i; o++) {
      token = strtok( line[o], delim );
      strcpy( students[o].nama, token );
      token = strtok( line[o], delim );
      strcpy( students[o].nim, token );
      token = strtok( line[o], delim );
      strcpy( students[o].angkatan, token );
      token = strtok( line[o], delim );
      strcpy( students[o].sex, token );
    }

    int male=0, female=0;
    for (int o=0; o<i; o++) {
      if
        ( strcmp( students[o].sex, "male" ) == 0 ) male++;
      else if
        ( strcmp( students[o].sex, "female" ) == 0) female++;
    }

    printf("%d|%d", male, female);
  }
  else { puts("0|0"); }
  
  return 0;

}