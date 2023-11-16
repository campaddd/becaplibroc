#include <stdio.h>
#define MAX_LEN 200

void getlin(char s[], int maxlen);
int printlinex(char line[]);
int any(char s[],char t[]);
int main()
{
    char s[MAX_LEN],t[MAX_LEN];
    int i;
    int idx[MAX_LEN];

    printf("inserisci s\n");
    getlin(s,MAX_LEN);
    printf("inserisci t\n");
    getlin(t,MAX_LEN);
    printf("il primo indice in s di una lettera in t è %d; la lettera in questione è la %c\n",any(s,t),s[any(s,t)]);

    return 0;
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

int any(char s[], char t[])
{
    int i,j;
    i=j=0;

    while(s[i]!='\0')
    {
        while(t[j]!='\0')
        {
            if(s[i]==t[j])
                return i;
            j++;
        }
        j=0;
        i++;
    }
    return -1;
}
