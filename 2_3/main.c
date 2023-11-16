#include <stdio.h>
#include <ctype.h>

#define HEX_LEN 4

//'a' = 97
void getnum(char s[],int maxlen);
int htoi(char s[]);

int main()
{
    int num;
    char s[HEX_LEN];
    getnum(s,HEX_LEN);
    num=htoi(s);
    printf("%d\n",num);
    return 0;
}

void getnum(char s[],int maxlen)
{
    int i,c;
    for(i=0;i<maxlen&&(c=getchar())!='\n'&&c!='\0';i++)
    {
        s[i]=c;
    }
}
int htoi(char s[])
{
#define DELTA 87 //differenza tra 'a' e 10, che è il valore di 'a' in hex
#define DELTANUM '0'
    int i,val;

    s[2]=tolower(s[2]);
    s[3]=tolower(s[3]);

    if((s[0]=='0'||s[0]=='o')&&(s[1]=='x'||s[1]=='X'))
    {
        i=2;
    }else
        i=0;

    if(!isdigit(s[i]))
    {
        s[i]=s[i]-DELTA;
    }else
        s[i]=s[i]-DELTANUM;
    if(!isdigit(s[i+1]))
    {
        s[i+1]=s[i+1]-DELTA;
    }else
        s[i+1]=s[i+1]-DELTANUM;

    printf("%d,%d\n",s[i],s[i+1]);
    val=s[i]*16+s[i+1];
    return val;
}
