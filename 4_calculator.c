#include <stdio.h>
#include <stdlib.h>         //for atof
#include <ctype.h>          //for isdigit
#define STACK_SIZE 20
#define BUFFER_SIZE 20      //characters that make up a number
#define NUMBER 0

int sp=0;                   //stack pointer of first empty location
double stack[STACK_SIZE];

double pop(void);
void push(double val_to_be_pushed);
void print_top(void);
char getop(char s[]);        //gets operation or operand
int main()
{
    char c,s[BUFFER_SIZE];
    double a,b;
    while((c=getop(s))!=-1){
        switch(c){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            a=pop();
            b=pop();
            push(a+b);
            break;
        case '*':
            a=pop();
            b=pop();
            push(a*b);
            break;
        case '\n':
            print_top();
            break;
        default:
            printf("main: switch case- default: something went wrong\n");
        }
    }
    return 0;
}

double pop(void){
    if(sp>0){
        sp--;
        return (stack[sp]);
    }else{
        printf("pop: stack empty!\n");
        return -1;
    }
}
void push(double val){
    if(sp<STACK_SIZE){
        stack[sp]=val;
        sp++;
    }else{
        printf("push: stack full!\n");
    }
}
void print_top(void){
    if(sp>0){
        sp--;
        printf("top of the stack (double): %lf\n", stack[sp]);
    }else{
        printf("print_top: the stack is empty!\n");
    }
}
char getop(char s[]){
#ifndef NUMBER
#define NUMBER 0
#endif;

    /*gets operation or operand: if operation returns the operator.
    if operand(number) returns 0, and fills s with the number, so that
    then s can be processed by atof*/
    int i;
    char c;

    while((c=getchar())==' '||c=='\t'){     //skip initial spaces and tabs
        ;
    }
    if(c=='+'||c=='*'||c=='\n'){             //'\n' is for ending expression
        return c;
    }
    if(!isdigit(c) && c!='-'){
        printf("getop: not a number: ");
        printf("%c\n",c);
        s[0]='\0';
        return -1;
    }
    i=0;
    if(c=='-'){
        s[0]='-';
        i++;                                //if c made it past here is a number
    }else{
        s[0]=c;
        i++;
    }
    while((c=getchar())!='.'&&isdigit(c)){  //integer part
        s[i]=c;
        i++;
    }
    if(c=='.'){
        s[i]=c;
        i++;
        while(isdigit(c=getchar())){        //fractional part
            s[i]=c;
            i++;
        }
    }
    s[i]='\0';
    return NUMBER;
}
