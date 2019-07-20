#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b);
void quicksorthelp(int *arr,int left,int right);
int main()
{
    int print_int(int *arr,int len);
    void quicksort(int *arr,int len);
    int test_index[]={1,4,4,3,1,0,9,8,6,5};
    quicksort(test_index,10);
    print_int(test_index,10);
    return 0;
}
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
void quicksort(int *arr,int len)
{
    quicksorthelp(arr,0,len-1);
}
void quicksorthelp(int *arr,int left,int right)//left and right here should be index
{
    int base=arr[left];
    int low=left+1;
    int high=right;
    int i;//counter
    if(left>=right)
        return;
    while(arr[low]>arr[high])
    {
        for(i=low;arr[i]<base&&i!=high;i++);
        low=i;
        for(i=high;arr[i]>base&&i!=low;i--);
        high=i;
        if(high-1!=low||low+1!=high)
        swap(&arr[low],&arr[high]);
    }

    swap(&arr[left],&arr[low]);

    quicksorthelp(arr,left,low-1);
    quicksorthelp(arr,high+1,right);

}
int print_int(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]<=arr[i+1])
        {
            printf("%d ",arr[i]);
        }
        else if(i==len-1)
        {
            printf("%d ",arr[i]);
        }
        else return -1;
    }
    printf("\n");
    return 1;
}
