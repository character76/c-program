#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
#define _DEBUG
int main()
{
int binary(int *a,int len,int key);
    int b_search(int *arr,int len,int key);
    int len,key,ans;
    int* data;
    if(scanf("%d %d",&len,&key)==2);
    for(int i=len-1;i>=0l;i--)
    {
        scanf("%d",&data[i]);
    }
    printf("ans:%d",binary(data,len,key));
    return 0;
}
int b_search(int *arr,int len,int key)
{
    if(arr==NULL||len<0)return 0;
    int* b_search_help(int *arr,int len,int key);//len: the number of the array
    int *ans=b_search_help(arr,len,key);
    #ifdef _DEBUG
    printf("address_m:%d\n",arr);
    #endif
    if(ans==NULL)
    return False;
    if(ans!=NULL)
    {
        return ans-arr;
    }

}
int* b_search_help(int *arr,int len,int key)//len: the number of the array
{
    if(len<0||len==0)
    {
    #ifdef _DEBUG
    printf("address:%d,len:%d\n",arr,len);
    #endif
        if(arr[0]==key)
        {
            return arr;
        }
        else return NULL;
    }
    if(len==1)
    {
    #ifdef _DEBUG
    printf("adress:%d,len:%d\n",arr,len);
    #endif
        if(key==arr[0])
        {
            return arr;
        }
        else return NULL;
    }
    int middle;
    int len_l,len_r;
    if(len%2==0)
    {
        middle=(len-1)/2;//the number of
        len_l=len/2;
        len_r=len/2;
    }
    else if(len%2==1)
    {
        middle=(len-1)/2;//the index of the middle one
        len_l=middle+1;
        len_r=len-middle-1;
    }
    #ifdef _DEBUG
    printf("middle index:",middle,len);
    #endif
    if(arr[middle]==key)
    return &arr[middle];
    if(arr[middle]<key)
    {
        return b_search_help(&arr[middle+1],len_r,key);
    }
    if(arr[middle]>key)
    {
        return b_search_help(&arr[0],len_l,key);
    }
}

int binary(int *a,int len,int key)
{
    int low,high=len-1;
    int middle=high/2;
    if(a[middle]==key)
    return middle;
    while(a[middle]!=key)
    {
        if(a[middle]>key)
        {
            high=middle-1;
        }   
        if(a[middle<key])
        {
            low=middle+1;
        }
        if(a[middle]==key)
        return middle+1;
        middle=high/2;
    }
    return -1;
}