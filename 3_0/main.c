#include <stdio.h>
#include <stdlib.h>
#define SIZE 9
#define TOP 80
void printarray(int v[],int n);
void fillarray(int v[], int n, int top);
void sortarray(int v[],int n);

int binsearch(int v[],int n, int x);
int main()
{
    int i,x;
    int v[SIZE];

    // section 1: filling and sorting the array
    fillarray(v,SIZE,TOP);
    sortarray(v,SIZE);
    printarray(v,SIZE);

    // section 2: searching using binsearch
    for(i=0;i<SIZE;i++)
    {
        printf("inserisci il numero da cercare nell'array!\n");
        scanf("%d",&x);
        (binsearch(v,SIZE,x)!=-1)?printf("il numero desiderato si trova in posizione %d\n",binsearch(v,SIZE,x)):printf("il numero non è presente\n");
    }
    return 0;
}
void printarray(int v[], int n){
    int i;
    printf("idx\telem\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\n",i,v[i]);
    }
    printf("\n");
}
void fillarray(int v[],int n,int top)
{
    //fills array of random numbers from 0 to top
    int i;
    for(i=0;i<n;i++){
        v[i]=rand()%top;
    }
}
int binsearch(int v[], int n, int x) //binary search in sorted array
{
    int i,num_iterations;
    num_iterations=0;
    int lower=0;
    int upper=n-1;
    while(num_iterations<n)
    {
        i=(upper+lower)/2;
        if (x>v[i])
        {
            lower=i;
        }else if(x<v[i])
        {
            upper=i;
        }else
        {
            return i;
        }
        num_iterations++;
    }
    return -1;
}
void sortarray(int v[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                temp=v[j+1];
                v[j+1]=v[j];
                v[j]=temp;
            }
        }
    }
}
