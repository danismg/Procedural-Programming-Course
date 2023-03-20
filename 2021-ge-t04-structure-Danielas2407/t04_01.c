// NIM - lile
// NIM - daniel

#include <stdio.h>
#include <string.h>

struct kamus_t {
char kata[20];
char artikata[80];} ;

int main(int _argc, char **_argv)
{
struct kamus_t kms[5];
char option;
for(a=0;a<5;a++){
        char option;
        scanf("%c", &option);
        if(strcmp(option, "---")==0){
            if(strcmp(option, "register")==0){
                gets(kms[a].kata);
                gets(kms[a].artikata);
            } else {
                char find;
                scanf("%c", &find);
                if(strcmp(find, kms[a].kata)==0){
                  if(find == kms[0].kata) {
                    printf("%s#%s,kms[0].kata,kms[a].artikata");
                  }
                  else if (find == kms[1].kata) {
                    printf("%s#%s,kms[1].kata,kms[a].artikata");
                  }
                  else if (find == kms[2].kata) {
                    printf("%s#%s,kms[2].kata,kms[a].artikata");
                  }
                  else if (find == kms[3].kata) {
                    printf("%s#%s,kms[3].kata,kms[a].artikata");
                  }
                  else if (find == kms[4].kata) {
                    printf("%s#%s,kms[4].kata,kms[a].artikata");
                  else {
                  }   
                }
            }
        }    
    }
return 0;
}
