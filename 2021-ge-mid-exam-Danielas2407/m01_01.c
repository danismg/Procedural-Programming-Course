#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct komponen_t{
  char nama[50];
  char persen[50];
  char nilai[100];
  char input[100];
};


int main(int _argc, char **_argv) {
  int z;
  for(int a = 0; a < _argc; a++) {
    z = atoi(_argv[a]);}

  int b;
  struct komponen_t kompe[z];
  struct komponen_t create_grade() {
    struct komponen_t kompe[z];
    for(b = 0; b < z; b++) {
      kompe[b] = create_grade();
      strcpy(kompe[b].nama, "");
      strcpy(kompe[b].persen, "");
      strcpy(kompe[b].nilai, "");
      strcpy(kompe[b].input, "");}}

  float gradee;
  float persentasi;
  float i_nilai;
  char *slice;

  for(b = 0; b < z; b++){
    char input2[100];
    short int input3 = 0;
    input2[0] = '\0';
      while(1) {
        char f = getchar();
         if (f != '\r' && f != '\n') {
        input2[input3] = f;
        input2[++input3] = '\0';
         }  
          else {
          if (f == '\r') {
          continue;
          }

          if (f == '\n') {
          break;
        };
        } 
        }
 strcpy(kompe[b].input, input2);
 slice = strtok(kompe[b].input, "#");
 int h = 0;
    while(slice != NULL) {
      if(h == 0) {
        strcpy(kompe[b].nama, slice);
        slice = strtok(NULL, "#");
        h = h + 1;
      }
      else if(h == 1) {
        strcpy(kompe[b].persen, slice);
        slice = strtok(NULL, "#");
        h = h + 1;
        
      }
      else if( h == 2) {
        strcpy(kompe[b].nilai, slice);
        slice = strtok(NULL, "#"); 
      }
    }
  }

for(b = 0; b < z; b++) {
  printf("%s;%s;%s\n", kompe[b].nama, kompe[b].persen, kompe[b].nilai);
}
float totalgrade = 0.0;
float ggrade = 0.0;

for(b = 0; b < z; b++); {
  persentasi = atof(kompe[b].nilai);
  i_nilai = atof(kompe[b].persen);
  ggrade = (i_nilai/100 )* persentasi;
  totalgrade = totalgrade + ggrade;
}

printf("%.1f\n", totalgrade);

if(totalgrade >= 50.0) {
  printf("passed\n");
}
else {printf("failed\n");}

  return 0;
}