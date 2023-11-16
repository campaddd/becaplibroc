#include <stdio.h>
#define TRUE 1
#define FALSE 0
//nota:funziona bene ma se fai \n subito dopo ultima cifra fa casino
int isdigit(int c);
int main()
{
    int c,sign,n;
    sign=0;
    n=0;

    while((c=getchar())!='\n')
    {
        if(c=='+'||c=='-'||isdigit(c)==1){
            if(sign==0){
                if(c=='+')  sign=1;
                if(c=='-')  sign=-1;
                if(isdigit(c)==1) {
                    sign=1;             //un numero che inizia come numero e basta è positivo
                    n=c-'0';
                }
            }else{
                n=10*n+(c-'0');
            }
        }else{
            if(sign!=0){
                n=sign*n;
                printf("il numero è %d\n",n);
            }
            sign=0;
        }
    }
    return 0;
}

int isdigit(int c)
{
    int r;
    r = c-'0';
    if(r<=9&&r>=0)
        return 1;
    else
        return 0;
}
