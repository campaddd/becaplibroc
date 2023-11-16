#include <stdio.h>
#define MAX_LEN 300
#define TRUE 1
#define FALSE 0

void getlin(char s[], int maxlen);
int printlinex(char line[]);
void squiz(char s[],char t[]);

int main()
{
    char s[MAX_LEN],t[MAX_LEN];
    int i;
    printf("inserisci s\n");
    getlin(s,MAX_LEN);
    getlin(t,MAX_LEN);
    squiz(s,t);
    printlinex(s);
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

void squiz(char s[], char t[])
{
    int i,j,k,presente;
    i=j=k=0;
    presente=FALSE;

    while(s[i]!='\0')
    {
        while(t[k]!='\0')
        {
            if(s[i]==t[k])
            {
                presente=TRUE;
            }
            k++;
        }
        k=0;    //resetto k per il prossimo giro
        if(presente==FALSE)
        {
            s[j]=s[i];
            j++;
        }
        presente=FALSE;
        i++;
    }
    s[j]=s[i];
}
