#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
#define Error
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
        return search_help(arr,&arr[middle],key);
        if(arr[middle]>key)
        return search_help(&arr[middle],&arr[len-1],key);
    }
}
int search_help(int* left,int* right,int key)
{
    int len=(right-left)/sizeof(int)+1;
    
    printf("len:%d",len);
    if(right-left==sizeof(int))
    {
        if(*left==key||*right==key)
        {
            return True;
        }
        else return False;
    }
    else if(right-left==0)
    {

    }
    else if(right-left>sizeof(int))
    {
        int* middle =left+(len/2)*sizeof(int);
        if(*middle==key)
        {
            return True;
        }
        else if(key<*middle)
        {
            return search_help(left,middle,key);    
        }
        else if(key>*middle)
        {
            return search_help(middle,right,key);
        }
    
    }
}
