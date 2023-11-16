#include <stdio.h>

void arr_init_0(int v[],int n);
int main()
{
    int c,nt,nl,ns;
    int digits[10];

    nt=nl=ns=0;
    arr_init_0(digits,sizeof(digits)/sizeof(int));

    while((c=getchar())!=EOF)
    {
        switch (c) {
        case '1':case '2':case '3':case '4':case '5':
        case '6':case '7':case '8': case '9': case '0':
            digits[c-'0']+=1;
            break;
        case '\t':
            ++nt;
            break;
        case '\n':
            ++nl;
            break;
        case ' ':
            ++ns;
            break;
        default:

            break;
        }
    }

    printf("aight we got: %d spaces, %d newlines, %d tabs\n",ns,nl,nt);

    printf("then we got the following:\ndigit\toccurrences\n");
    for(c=0;c<10;c++)
    {
        if(digits[c]!=0) printf("%d\t%d\n",c,digits[c]);

    }
    return 0;
}
void arr_init_0(int v[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        v[i]=0;
    }
}
