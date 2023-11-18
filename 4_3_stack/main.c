#include <stdio.h>
#define SUM_OPERANDS 2
#define TIMES_OPERANDS 2
#define STACK_SIZE 10
int isdigit(short int c);
int main()  //programma che somma dei numeri o li inverte, in polish notation
{
    short int c;
    short int i;
    short int stack[STACK_SIZE];
    i=0;

    while((i<STACK_SIZE-1)&&(c=getchar())!='\n')
    {
        if(isdigit(c)){
            c=c-'0';            //conversion to digit
            stack[i]=c;         //push on top of the stack
            i++;                //incrementing the next stack position
        }
        if(c=='+'){
            c=stack[i-1]+stack[i-2];
            i-=2;
            stack[i]=c;
            i++;
        }
        if(c=='*'){
            c=stack[i-1]*stack[i-2];
            i-=2;
            stack[i]=c;
            i++;
        }
    }
    if(i==STACK_SIZE-1){
        printf("stack overflow!\n");
        return -1;
    }else{
        printf("result is: %d\n",stack[i-1]);
        return 0;
    }
}

int isdigit(short int c){
    if(c-'0'>=0&&c-'0'<=9)    return 1;
    else                      return 0;
}
