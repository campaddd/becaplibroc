#include <stdio.h>
#include <utilities_cap1.h>
#define FALSE 0
#define TRUE 1
#define AROUND 3
int getstring_y(char s[], int n);
int troubleshooter(char s[]);
int grepy(char s[], char pattern[],int around);
int ceily(int a, int b);
void idxprint(char s[], int idx, int neighborhood);
int max(int a,int b);

int main()
{
    char s[MAX_LEN],pattern[MAX_LEN];

    printf("testo in cui cercare\n");
    getstring_y(s,MAX_LEN);

    printf("\npattern da cercare\n");
    getstring_y(pattern,MAX_LEN);

    grepy(s,pattern,AROUND);
    return 0;
}

int grepy(char s[], char pattern[], int around)
{
    int i,j,k,l,inpattern;
    int palen,slen,idxlen,linelen;

    palen=slen=linelen=0;
    inpattern=FALSE;

    //retrieve string lenght and number of lines
    i=0;
    while(s[slen]!='\0'){
        slen++;
        if(s[slen-1]=='\n') linelen++;
    }
    slen++;
    int line[max(1,linelen)];

    //retrieve pattern lenght
    while(pattern[palen]!='\0'){
        palen++;
    }
    palen++;
    // create array of indeces of at least the lenght of s/pattern, case that happens when the pattern repeats continuously
    idxlen=ceily(slen,palen);
    int idx[idxlen];
    for(k=0;k<idxlen;k++){
        idx[k]=-1;
    }

    // i is s index, j is patten index, k is idx index, l is current line
    i=k=l=0;

    //sweep through s
    while(s[i+palen-1]!='\0'){
        if(s[i-1]=='\n') l++;       //keep track of current line
        if (s[i]==pattern[0]){
            inpattern=TRUE;
            for(j=0;j<palen-1;j++){
                if(s[i+j]!=pattern[j]) inpattern=FALSE;
            }
            if (inpattern==TRUE){
                idx[k]=i;
                line[k]=l;
                k++;
            }
            inpattern=FALSE;
        }
        i++;
    }

    for(i=0;idx[i]!=-1&&i<slen;i++){                        //printing output
        printf("%d..\t",line[i]);
        idxprint(s,idx[i]+palen/2,around+palen/2);
        putchar('\n');
    }
    if(idx[0]==-1)
        return -1;
    else
        return k;
}
void idxprint(char s[], int idx, int n)
{
    int i;
    for(i=max(idx-n,0);i<=idx+n;i++){
        if(s[i]!='\n'&&s[i]!='\t') putchar(s[i]);
    }
}
int troubleshooter(char s[])
{
    int i;
    i=0;
    while(s[i]!='\0')
    {
        if(s[i]<32&&s[i]!='\n'&&s[i]) return i;
        i++;
    }
    return -1;
}
int getstring_y(char s[], int n)
{
    int c,i;
    i=0;
    while(i<n-1&&(c=getchar())!='$')
    {
        if(c!='\n'||i>0){
            s[i]=c;
            i++;
        }
    }
    i++;
    s[i]='\0';

    //a volte compariva roba a caso vediamo di spottarla!
    if(troubleshooter(s)!=-1)
    {
        printf("erroreee in posizione %d, c'è il carattere %d",troubleshooter(s),s[troubleshooter(s)]);
            return -1;
    }
    return i;
}
int ceily(int a, int b){
    if(a%b>0)   return (a/b)+1;
    else return (a/b);
}
int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}
