#include<stdio.h>
#include<math.h>

int counter(int n);
int main()
{
    int n,ans;
    int spuare;
    int a[100000]={0};
    scanf("%d",&n);
    a[1]=1;
    int p;
    for(int i=2;i<n||i==n;i++)
    {

        if(a[i]==0)
        {
            ans=counter(i);
            a[i]=ans;
            #ifdef DEBUG
            printf("ans:%d\n",ans);
            #endif // DEBUG
            if(i==2)
            {
                p=1;
            for(int j=2;j<n||j==n;j++)
            {

                a[i*j]=ans+p;
                p++;
            }
            }
        }
        if(a[i]!=0)
            continue;

    }
    #ifdef DEBUG
    printf("a:");
    #endif
    ans=0;
    for(int i=1;i<n||i==n;i++)
    {
        #ifdef DEBUG
        printf(" %d ",a[i]);
        #endif
        ans+=a[i];
    }
    #ifdef DEBUG
    printf("a_end ");
    #endif
    printf("%d",ans);
    return 0;
}
int counter(int n)
{

    if(n==1)
        return 1;
        double g;
    int ans=0;
    g=pow(n,0.5);
    for(int i=1;i<g||i==g;i++)
    {
        if(n%i==0&&i!=g)
        {
            ans+=2;
        }
    if(i==g)
    ans+=1;

    }
   return ans;
}

long int qpow(int a,int b)
{
    for(int i=1;i<b;i++)
        a*=a;
    return a;
}
/*
right code:
#include<stdio.h>

int main()
{
    int n;
    int ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    ans+=n/i;
    printf("%d",ans);
    return 0;
}
*/
