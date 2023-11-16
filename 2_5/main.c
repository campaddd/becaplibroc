#include <stdio.h>
#define MAX_LEN 300
#define TRUE 1
#define FALSE 0

void getlin(char s[], int maxlen);
int printlinex(char line[]);
void any(char s[],char t[],int idx[]);
void initialize_indeces(int idx[],int l);

int main()
{
    char s[MAX_LEN],t[MAX_LEN];
    int i;
    int idx[MAX_LEN];
    initialize_indeces(idx,MAX_LEN);

    printf("inserisci s\n");
    getlin(s,MAX_LEN);
    printf("inserisci t\n");
    getlin(t,MAX_LEN);
    any(s,t,idx);

    return 0;
}

void initialize_indeces(int idx[], int l)
{
    int i;
    i=0;

    for(i=0;i<l;i++)
    {
        idx[i]=-2;  //così poi uso -2 come terminazione
    }
}
void getlin(char s[],int maxlen)
{
    int i,c;    //con \0 (CTRL+D) fa casini in terminale, quindi ho messo '\n'come terminazione
    for (i=0;i<maxlen&&(c=getchar())!='\n';i++)
        s[i]=c;
    i++;
    s[i]='\0';
}

int printlinex(char line[])
{
    int i;
    for(i=0;line[i]!='\0';i++)
    {
        if(line[i]=='\n') putchar(126);
        if(line[i]=='\0') putchar(123);
        else        putchar(line[i]);
    }

}

void any(char s[], char t[], int idx[])
{
    int i,j;

}
