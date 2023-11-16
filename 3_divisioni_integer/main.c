#include <stdio.h>

int main()
{
    int a,i,r,temp;
    a=55;
    for(;a>0;){
        r = a/2;
        printf("l'operazione %d/2 dà come risultato: %d\n",a,r);
        a=r;
    }
    return 0;
}
