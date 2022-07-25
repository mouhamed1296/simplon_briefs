#include <string.h>

//fonction permettant de tester si une variable est un entier
int est_entier(char s[2]) {
    int count = 0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
                count++;
        }
        
    }
    if (count == strlen(s))
    {
        return 1;
    }
    
    return 0;
}