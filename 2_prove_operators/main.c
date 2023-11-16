#include <stdio.h>
#define SIZEARR 8
#define ELEM_PER_LINE 3

int max(int a,int b);
int main()
{
    int nums[SIZEARR]={4,3,78,1,24,67,3,90};
    int i;
    /*for(i=0;i<SIZEARR;i++)
    {
        printf("%6d%c",nums[i],(i%ELEM_PER_LINE==2||i==SIZEARR-1)?'\n':' ');    //nota:non uso la condizione i%3==0 perchè per i=0 ogni modulo è 0
    }*/
    for(i=0;i<SIZEARR;i++)
    {
        printf("you have %d element%c\n",nums[i],(nums[i]==1)?' ':'s');
    }

    //printf("il max è: %d\n",max(4,4));



    return 0;
}

int max(int a,int b)
{
    return (a>=b)?a:b;
}
