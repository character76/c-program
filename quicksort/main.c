#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b);
void quicksorthelp(int *arr,int left,int right);
static void quickSortHelp(int* arr,int first,int last);
int debug_print(int *arr,int len);
int main()
{
    int print_int(int *arr,int len);
    void quicksort(int *arr,int len);
    int test_index[]={1,4,4,3,5,0,9,8,6,5};
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
    if(left>=right)
        return;
    int base=arr[left];
    int low=left+1;
    int high=right;
    int i;//counter

    while(low<high)
    {
        while((arr[low]<=base)&&(low<right))
        {
            low++;
        }
            printf("low:%d\n",low);

        while((arr[high]>base)&&(high>left))
            {
                    high--;
            }
            printf("high:%d\n",high);
            if(low<high)
        swap(&arr[low],&arr[high]);
        printf("at point end while low:%d,high:%d arr:",low,high);
        debug_print(arr,right-left+1);

    }
    if(base>arr[high])
    {
        swap(&arr[left],&arr[high]);
    }
    debug_print(arr,right-left+1);
    printf("low:%d,high:%d and recursion start\n",low,high);
    quicksorthelp(arr,left,high-1);

    quicksorthelp(arr,low,right);

}
/*
quickSortHelp:
according to Intermediate C Programming by Yung-Hsiang Lu
*/
static void quickSortHelp(int* arr,int first,int last)
{
    if(first>=last)
    {
        return;
    }
    int pivot=arr[first];
    int low=first+1;
    int high=last;
    while(low<high)
    {
        while((arr[low]<=pivot)&&(low<last))
        {
            low++;
        }
            printf("low:%d\n",low);

        while((arr[high]>pivot)&&(high>first))
            {
                    high--;
            }
            printf("high:%d\n",high);
            if(low<high)
{
            swap(&arr[low],&arr[high]);
            }
        printf("at point end while low:%d,high:%d arr:",low,high);
        debug_print(arr,last-first+1);

    }
    if(pivot>arr[high])
    {
        swap(&arr[first],&arr[high]);
    }
    debug_print(arr,last-first+1);
    printf("low:%d,high:%d and recursion start\n",low,high);
    quickSortHelp(arr,first,high-1);
    quickSortHelp(arr,low,last);
}
int print_int(int *arr,int left,int right)
{
    for(int i=left;i<=right;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 1;
}

int debug_print(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    return 1;
}
