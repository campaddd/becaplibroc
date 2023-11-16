#include <stdio.h>
#define MAX_LEN 400
#define SMALL_A 97
#define ALFABET_LENGHT (122-97)
#define SMALL_Z (SMALL_A+ALFABET_LENGHT)

#define BIG_A 65
#define BIG_Z (BIG_A+ALFABET_LENGHT)
#define UNDEFINED -1

void initstring(char s[], int n);
int getstring(char s[], int n);

void printstring(char s[]);
void expand(char s1[],char s2[]);
int main()
{
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    initstring(s1,MAX_LEN);
    initstring(s2,MAX_LEN);
    getstring(s1,MAX_LEN);
    printf("hai inserito: "); printstring(s1);    printf("\n");
    expand(s1,s2);
    printstring(s2);
    return 0;
}

void expand(char s1[],char s2[])
{
    int i,j,opener,closer,temp,k;
    i=j=opener=closer=0;

    while(s1[i]!='\0'){
        if(s1[i]=='-'){
            if(s1[i-1]>=SMALL_A&&s1[i-1]<=SMALL_Z){
                opener=s1[i-1];
                closer=SMALL_Z;
            }

            if(s1[i+1]>=SMALL_A&&s1[i+1]<=SMALL_Z){
                closer=s1[i+1];
                if(opener==0)  {
                    opener=SMALL_A;
                    // s2[j]=s1[i-1];    //causa problemi in terminazione
                    // j++;
                }
            }

            printf("%c,%c\n",opener,closer);
            if(opener>closer){
                temp=closer;
                closer=opener;
                opener=temp;
            }

            for(k=0;k<(closer-opener);j++,k++){
                s2[j]=opener+k;
            }


            opener=0;
            closer=0;
        }else if(s1[i+1]!='-'){
            s2[j]=s1[i];
            j++;
        }
        i++;
    }
    j++;
    s2[j]='\0';
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
    while(i<n-1&&(c=getchar())!='\n')
    {
        s[i]=c;
        i++;
    }
    i++;
    s[i]='\0';
    return i;
}

void initstring(char s[], int n){
    int i;
    for(i=0;i<n;i++) s[i]='\0';
}
