#include <stdio.h>
#include <stdlib.h>
int print_int(int *arr,int len);
void swap(int *a,int *b);
int len;
int situation=0;//to store how many situations we have
int main()
//this main only for testing
{
    int permute(int *arr,int len);
    int arr[]={5,9,5,7,2};
    permute(arr,5);
    printf("%d",situation);
    return 0;
}
int permute(int *arr,int len)
{
    void permutehelp(int *arr,int ink,int num);
    permutehelp(arr,0,len);
    return situation;
}
void permutehelp(int *arr,int ink,int num)
{
    if(num==ink)
    {
        print_int(arr,num);
        situation++;
    }
    for(int i=ink;i<num;i++)
    {
        swap(&arr[ink],&arr[i]);
        permutehelp(arr,ink+1,num);
        swap(&arr[ink],&arr[i]);
    }
}
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int print_int(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
            printf("%d ",arr[i]);
    }
    printf("\n");
    return 1;
}

