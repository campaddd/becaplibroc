#include <stdio.h>
#define MAXLEN 200
void printstring(char s[]);
int getstring(char s[], int n);
void trim(char s[]);
int main()
{
    char s[MAXLEN];
    getstring(s,MAXLEN);
    //printstring(s);
    trim(s);
    printstring(s);
    return 0;
}

void trim(char s[])
{
    int len;
    for(len=0;s[len]!='\0';len++)
        ;
    len--;  //altrimenti dopo testa su '\0'!
    for(;s[len]==' '||s[len]=='\t'||s[len]=='\n';len--)
    {
        s[len]='\0';
    }
}


int getstring(char s[], int n)
{
    int c,i;
    i=0;
    while(i<n-1&&(c=getchar())!=EOF)
    {
        s[i]=c;
        i++;
    }
    i++;
    s[i]='\0';
    return i;
}
void printstring(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        //if(s[i]=='\n') putchar(126);
        putchar(s[i]);
        i++;
    }
    if (s[i]=='\0')
        putchar('#');
}
