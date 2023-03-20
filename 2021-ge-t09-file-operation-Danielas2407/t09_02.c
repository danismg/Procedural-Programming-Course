// 12S21006 - Weny S. M Sitinjak
// 12S21020 - Priskila C. N Parapat

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef enum {
    MALE, 
    FEMALE
} jeniskelamin;

typedef struct mahasiswa
{
    char input[10];
    char datamhs[100];
    char namamale[50];
    char namafemale[50];
    int jlhmale;
    int jlhfemale;
}Mahasiswa;

int main (){
    Mahasiswa _mahasiswa;
    _mahasiswa.jlhmale=0;
    _mahasiswa.jlhfemale=0;
    int jlhmale=0;
    int i=0,j=0,k;
    scanf("%s", _mahasiswa.input);
    do
    {
        if (strcmp(_mahasiswa.input, "---")==0) {
           break;
        } else {
            scanf("%s", &_mahasiswa.datamhs);
            if (strcmp(_mahasiswa.datamhs, "---")==0) {
                _mahasiswa.namafemale[i] = '\0';
                _mahasiswa.namamale[j] = '\0';
                break;
            }
            if (strstr(_mahasiswa.datamhs,"FEMALE")!=NULL)
            {
                _mahasiswa.jlhfemale++;
                k=0;
                while (_mahasiswa.datamhs[k]!='|'){
                    _mahasiswa.namafemale[i] = _mahasiswa.datamhs[k]; 
                    i++;
                    k++;
                }
                _mahasiswa.namafemale[i] = '|';
                i++;
            } else {
                _mahasiswa.jlhmale++;
                k=0;
                while (_mahasiswa.datamhs[k]!='|'){
                    _mahasiswa.namamale[j] = _mahasiswa.datamhs[k]; 
                    j++;
                    k++;
                }
                _mahasiswa.namamale[j] = '|';
                j++;
            }
        }
        
    } while (strcmp(_mahasiswa.input, "---")!=0 && strcmp(_mahasiswa.input, "register")==0);
    
    printf("%d|%d\n", _mahasiswa.jlhmale, _mahasiswa.jlhfemale);
    printf("%s\n", _mahasiswa.namamale);
    printf("%s", _mahasiswa.namafemale);
    return 0;
}