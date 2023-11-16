#include <stdio.h>
#define MAX_SIZE 20
#define HEX 16
#define A_DISTANCE 64
void itob(int n,char s[],int b);
void printstring(char s[]);
int reverse(char line[],int maxl);
int main()
{
    int n;
    char s[MAX_SIZE];
    printf("inserisci numero da convertire: ");
    scanf("%d",&n);
    itob(n,s,16);
    reverse(s,MAX_SIZE);
    printstring(s);

    return 0;
}
void itob(int n,char s[],int b)
{
    int i,r;
    char c;
    i=r=0;


    do{
        // calcolo resto r
        r=n%b;
        n=n/b;

        //trasformo r in base b in char
        if(r-9>0){
            c=(r-9)+A_DISTANCE;
        }else{
            c=r+'0';
        }

        s[i]=c;
        i++;
    }while(n!=0);

    s[i]='\0';
}


int reverse(char line[],int maxl)
{
    int i,len;
    char reversed[maxl];

    i=0;
    while(line[i]!='\0')
    {
        i++;
    }
    len=i;

    for(i=0;i<len;i++)
    {
        reversed[len-i-1]=line[i];
    }

    for(i=0;i<len;i++)
    {
        line[i]=reversed[i];
    }

    return 0;
}
void printstring(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]!='\n')
            putchar(s[i]);
        else
            putchar(126);
        i++;
    }
    if (s[i]=='\0')
        putchar('#');
}
