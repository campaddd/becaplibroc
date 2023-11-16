#include <stdio.h>
#define MIAO 12345

int main()
{
    const char frase[]="hey cowboy";
    int i;
    printf("miao:%d\nlongint:%d\n",sizeof(MIAO),sizeof(long));

    for(i=0;frase[i]!='\0';i++)
    {
        putchar(frase[i]);
    }
    return 0;
}
