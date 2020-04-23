#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
#define Error 65565
//basic review of binary search and quicksort
int main()
{
    int search(int *arr,int len,int key);
    int search_help(int* left,int* right,int key);
    int len,key,ans;
    int* data;
    if(scanf("%d %d",&len,&key)==2);
    for(int i=len-1;i>=0l;i--)
    {
        scanf("%d",&data[i]);
    }
    ans=search(data,len,key);
    printf("ans:%d",ans);
    return 0;
}

int search(int *arr,int len,int key)
{
int search_help(int* left,int* right,int key);
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
        if(arr[middle]==key)
            return True;
    }
}
int search_help(int* left,int* right,int key)
{
    int a,b,len=(right-left);

    printf("adress%d %d,len:%d\n",right,left,len);
    if(len==1)
    {
        if(*left==key||*right==key)
        {
            return True;
        }
        else return False;
    }
    else if(len==0)
    {
        if(*left==key)
            return True;
        if(*left!=key)return False;
    }
    else if(right-left>1)
    {
        int* middle =left+(len/2);
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
    else return False;
}
int b