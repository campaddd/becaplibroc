#include <stdio.h>
#include <ctype.h>          //for isdigit
#include <stdlib.h>         //for atof

#define LEN 200
#define STACK_SIZE 64
#define BUFSIZE 1
#define CMD_LEN 100

#define SEPARATION_CHAR '_'   //sepraration char used in cmds
#define EXIT -3
#define NAN -1
#define NUMBER 0
#define CLEAR 1
#define LIST 2
#define REMOVE 3

double stack[64];
int sp=0;
char cmds[CMD_LEN]="c_l_rm_ps";    //where the available operation are stored
int cmdsp=0;                    //pointer to current location in cmds
int cmdnum=1;                   //number of current operation being analized,see the defines above
char buf[BUFSIZE];
int bufp=0;                     //pointer to first free position in buf

char getch(void);               //gets a character, from the buffer or from getchar
void putch(char c);             //puts a character to the top of the buffer
int eq(char a[],char b[]);      //checks if two strings are equal
void part(char s[],char p[],int idx,int n);  //takes n chars from s starting from idx, puts in p
int getnextcmd(char nc[]);     //reads the extern variable cmds and saves single cmds in the char[] passed by value. Returns 0 if there are still cmds available. Otherwise, returns -1.
double getop(char s[]);        //gets operation or operand: operand: number(real w/ optional -).
                               //operand: progressive number of cmd present in extern var cmds, starting
                               //from 1

double pop(void);
void push(double val);
void list_stack(void);

int main()
{
    char s[LEN];
    char p[LEN];

    char c;

    while((c=getop(s))!=EXIT){
        printf("ecco cosa ha sputato fuori getcmd: %d",c);
        switch(c){
        case NUMBER:
            printf("the number is: %lf\n",atof(s));
            break;
        case NAN:
            printf("nan\n");
        }
    }
    return 0;
}

int eq(char a[],char b[]){
    int i=0;
    while(a[i]!='\0'||b[i]!='\0'){
        if (a[i]!=b[i]) return 0;
        i++;
    }
    if(a[i]!=b[i]){
        return 0;
    }else{
        return 1;
    }
}
void part(char s[],char p[],int idx,int n){
    int i=0;
    while(i<n&&s[idx+i]!='\n'&&s[idx+i]!='\0'){
        p[i]=s[idx+i];
        i++;
    }
    p[i]='\0';
}
char getch(void){
    if(bufp==0){
        return getchar();
    }else{
        bufp--;
        return buf[bufp];     //because bufp signals the first free location

    }
}
void putch(char c){
    if(bufp>=BUFSIZE){
        printf("putch: il buffer è pieno");
    }else{
        buf[bufp]=c;
        bufp++;
    }
}
int getnextcmd(char nc[]){
    int i=0;
    if(cmds[cmdsp]=='\0'){
        cmdsp=0;
        cmdnum=0;
        return -1;
    }
    while(cmds[cmdsp]!=SEPARATION_CHAR&&cmds[cmdsp]!='\0'){
        nc[i]=cmds[cmdsp];
        i++;
        cmdsp++;
    }
    nc[i]='\0';

    if(cmds[cmdsp]==SEPARATION_CHAR){
        cmdsp++;                    //otherwise @next call it will never enter the while
        cmdnum++;
        return (cmdnum-1);
    }else{
        cmdnum++;                   //cmdsp not incremented otherwise @nextcall the first if of funcion will do segmentation error
        return (cmdnum-1);
    }
}
double pop(void){       //works with double stack, idx: sp
    if(sp>0){
        sp--;
        return (stack[sp]);
    }else{
        printf("pop: stack empty! results could be affected\n");
        return -1;      //questo è un problema, perchè pop ritorna -1 con lo stack vuoto
    }
}
void push(double val){  //works with double stack, idx:sp, STACK_SIZE
    if(sp<STACK_SIZE){
        stack[sp]=val;
        sp++;
    }else{
        printf("push: stack full!\n");
    }
}
void list_stack(void){
    printf("idx\tstack\n");
    if(sp>0){
        int i;
        for(i=0;i<sp;i++){
            printf("%d\t%lf\n",i,stack[i]);
        }
    }else{
        printf("------------\n");
    }
}

double getop(char s[]){
    char c;
    char cmd[LEN],nc[LEN];
    int i=0;
    while ((c=getch())==' '||c=='\t'||c=='\n'){    //skip initial blanks
        ;
    }
    if(c=='-'){                                   //NUMBER SECTION
        s[i]='-';
        i++;
        c=getch();
    }
    if (isdigit(c)){
        s[i]=c;
        i++;
        while(isdigit(c=getch())){
            s[i]=c;
            i++;
        }
        if(c=='.'){
            s[i]='.';
            i++;
            while(isdigit(c=getch())){
                s[i]=c;
                i++;
            }
        }
        s[i]='\0';
        return NUMBER;
    }
    putch(c);           /*perchè la condizione di uscita del while mi fa perdere un carattere di informazione nel prossimo getchar--> infatti non uso più getchar ma getch*/
    //da qui in poi non è un numero: può essere un comando oppure garbage

    i=0;
    while((c=getch())!=' '&&c!='\t'&&c!='\n'&&c!='\0'){      //i comandi finiscono con blank
        cmd[i]=c;
        i++;
    }
    cmd[i]='\0';
    while((c=getnextcmd(nc))!=-1){
        if (eq(cmd,nc)==1)  return c;
    }

    return NAN;


}

