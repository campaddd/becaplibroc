#include <stdio.h>
#define MAX_LEN 200
#define FALSE 0
#define TRUE 1

void getline2(char line[],int maxlen);
void printline(char line[]);
int lower(int c);

int main()
{
    char line[MAX_LEN];
    getline2(line,MAX_LEN);
    printline(line);
    return 0;
}

void getline2(char line[], int maxlen)
{
    int i,c,exit;
    exit=FALSE;
    for(i=0;exit==FALSE;i++)
    {
        if(i<maxlen-1){
            if((c=getchar())!='\n')
            {
                if(c!=EOF)
                {
                    line[i]=c;
                }else
                    exit=TRUE;
            }else
                exit=TRUE;
        }else
            exit=TRUE;
    }
    i++;
    line[i]='\0';
}

void printline(char line[])
{
    int i =0;
    while(line[i]!='\0')
    {
        line[i]=lower(line[i]);
        putchar(line[i]);
        i++;
    }
}

int lower(int c)
{
    if(c>='A'&&c<='Z')  //c>='0'&&c<='9' può essere sostituito da tolower
        c=c-('A'-'a');
    return c;
}
