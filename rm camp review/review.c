#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
//basic review of binary search and quicksort
int main()
{
    return 0;
}

int search(int *arr,int len,int key)
{
    if(len==1)
    {
        if(arr[len]==key)
        {
             return True;
        }
    }
    int middle=len/2;
    if(len>1)
    {
        if(arr[middle]<key)
        search_help(arr,&arr[middle],key);
        if(arr[middle]>key)
        search_help(&arr[middle],&arr[len-1],key);
    }
}
int search_help(int* left,int* right,int key)
{
    if(right-left==1)
    {
        if(arr[right]==key||arr[left]==key)
        {
        return True;
        }
        else return False;
    }
    else if(right-left==0)
    {
        
    }
}
