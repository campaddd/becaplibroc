#include <stdio.h>
#include <utilities_cap1.h>
#define FALSE 0
#define TRUE 1
int getstring_y(char s[], int n);
int troubleshooter(char s[]);
int grepy(char s[], char pattern[]);
int ceily(int a, int b);
int main()
{
    char s[MAX_LEN],pattern[MAX_LEN];

    printf("testo in cui cercare\n");
    getstring_y(s,MAX_LEN);
    printstring(s);

    printf("\npattern da cercare\n");
    getstring_y(pattern,MAX_LEN);
    printstring(pattern);
    grepy(s,pattern);
    return 0;
}

int grepy(char s[], char pattern[])
{
    short int i,j,k,inpattern;
    short int palen,slen,idxlen;

    palen=slen=0;
    inpattern=FALSE;

    //retrieve string lenght
    while(s[slen]!='\0'){
        slen++;
    }
    slen++;
    printf("\nslen %d\n",slen);
    //retrieve pattern lenght
    while(pattern[palen]!='\0'){
        palen++;
    }
    palen++;
    printf("palen %d\n",palen);
    // create array of indeces of at least the lenght of s/pattern, case that happens when the pattern repeats continuously
    idxlen=ceily(slen,palen);
    unsigned int idx[idxlen];
    for(k=0;k<idxlen;k++){
        idx[k]=-1;
    }
    printf("idxlen %d\n",idxlen);
    // i is s index, j is patten index, k is idx index
    i=k=0;
    //sweep through s
    while(s[i+palen-1]!='\0'){
        if (s[i]==pattern[0]){
            inpattern=TRUE;
            for(j=0;j<palen-1;j++){
                if(s[i+j]!=pattern[j]) inpattern=FALSE;
            }
            if (inpattern==TRUE){
                idx[k]=i;
                k++;
            }
            inpattern=FALSE;
        }
        i++;
    }

    for(k=0;idx[k]!=-1;k++){
        printf("occorrenza numero %d in posizione %d\n",k+1,idx[k]);
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
