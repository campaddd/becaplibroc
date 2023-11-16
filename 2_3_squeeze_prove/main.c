#include <stdio.h>
#define MAXLEN 300

int end_idx(char s[]);
void getlin(char s[],int maxlen);
int printlinex(char line[]);
void squeeze(char line[],char c);
int main()
{
    char line[MAXLEN];
    getlin(line,MAXLEN);
    printf("indice slash0 prima dello squeeze: %d\n",end_idx(line));
    squeeze(line,'b');
    printf("indice slash0 dopo dello squeeze: %d\n",end_idx(line));
    printlinex(line);
    return 0;
}
void squeeze(char line[],char c)
{
    int i,j;
    for(i=j=0;line[i]!='\0';i++)
    {
        if(line[i]!=c)
        {
            line[j]=line[i];
            j++;
        }
    }
    line[j]='\0';
}
int end_idx(char s[])
{
    int i;
    i=0;
    while(s[i]!='\0')
        i++;
    return i;
}
void getlin(char s[],int maxlen)
{
    int i,c;
    for (i=0;i<maxlen&&(c=getchar())!=EOF;i++)
        s[i]=c;
}

int printlinex(char line[])
{
    int i;
    for(i=0;line[i]!='\0';i++)
    {
        putchar(line[i]);
    }
}
