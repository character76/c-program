#include<stdio.h>
#include<stdlib.h>
int print_sc(int num,int times);
int main()
{
    int n;
    int x[100]={-101};
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }

    for(int i=0;i<n||i==n;i++)
    {
        if(i==0)
        {
            if(x[i]!=1&&x[i]!=-1)
            printf("%dx^%d",x[i],n);
            if(x[i]==1)
                printf("x^%d",n);
            if(x[i]==-1)
                printf("-x^%d",n);
        }
        else
        {
            print_sc(x[i],n-i);
        }


    }
    return 0;
}
int cmp(const void* arg1,const void* arg2)
{
    const int * ptr1=(const int*)arg1;
    const int* ptr2=(const int *)arg2;
    const int val1=*ptr1;
    const int val2=*ptr2;
    if(val1<val2)
    {
        return 1;
    }
    if(val1==val2)
    {
        return 0;
    }
    return -1;
}

int print_sc(int num,int times)
{
    if(num>0&&times!=0&&times!=1)
    {
        if(num==1)
        {
            printf("+x^%d",times);
            return 0;
        }
        printf("+%dx^%d",num,times);
        return 0;
    }
    else if(num<0&&times!=0&&times!=1)
    {
        if(num==-1)
        {
            printf("-x^%d",times);
            return 0;
        }
        printf("%dx^%d",num,times);
        return 0;
    }
    else if(num==0)
    {
        return 0;
    }
    else if(times==1)
    {
        if(num>0)
        {
            if(num!=1){
            printf("+%dx",num);
            return 0;
            }
            if(num==1)
                {
                printf("+x");
            return 0;
            }
        }
        if(num<0)
        {
            if(num!=-1){
            printf("%dx",num);
            return 0;}
            if(num==-1)
                {
                printf("-x");
            return 0;
            }
        }
        if(num==0)
            return 0;
    }
    else if(times==0)
    {
        if(num>0){
            if(num==1)
        {
            printf("+1");
            return 0;
        }
        printf("+%d",num);
        }
        if(num<0)
        {
                printf("%d",num);
        }
        if(num==0)
            return 0;
    }
    return 25565;
}
