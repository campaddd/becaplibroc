#include <stdio.h>
#include <limits.h>
int main()
{
    //printf("%d\n",sizeof(unsigned long int));
    /* char: 1byte
     * int: 4byte
     * short int 2
     * long int 8
     * float 4
     * double 8
     */

    //printf("%ld\n",LONG_MAX); //da qui capisco che ho un compilatore a 64 bit --> dunque anche una macchina a 64 bit!
    printf("%ld\n",INT_MAX);
    int i;
    i= 2222222222L;
    printf("valore i\n%d\n",i);

    if (i>INT_MAX)
    {
        printf("stampo i%ld\n",i);
    } else
        printf("gianni\n");

    return 0;
}
