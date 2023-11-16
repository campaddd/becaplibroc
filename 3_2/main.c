#include <stdio.h>
#define MAX_LEN 300
int getstring(char s[], int max_len);
void printstring(char s[]);
void escape(char s[],char t[]);

int main()
{
    char s[MAX_LEN],t[MAX_LEN];
    getstring(s,MAX_LEN);
    escape(s,t);
    printf("printiamo la stringa con i char esposti\n");
    printstring(t);
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
void escape(char s[],char t[])
{
    int i,j;
    i=j=0;

    while(s[i]!='\0'){
        switch(s[i])
        {
        case ' ': t[j]='_';
            break;
        case '\t':
            t[j]=92;    //ascii code for fwdslash
            j++;
            t[j]='t';
            break;
        case '\n':
            t[j]=92;    //ascii code for fwdslash
            j++;
            t[j]='n';
            break;
        default:
            t[j]=s[i];
            break;
        }
        i++;
        j++;
    }
}
