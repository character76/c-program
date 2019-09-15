#include <cstdio>
#include <algorithm>
#define DEBUG
int mem[100000]={0};
int f[100005]={0};
int ans=0;

using namespace std;
int main()
{

    int walk2(int n,int k);
    int walk1(int n,int k);
    int n,k,ans;
    scanf("%d %d",&n,&k);
    walk2(n,k);
    walk1(n,k);
    #ifdef DEBUG
    printf("ans: ");
    #endif
    printf("%ld\n",mem[n]);
    
    #ifdef DEBUG
    printf("|||| ");
    #endif

    #ifdef DEBUG
    for(int i=1;mem[i]!=0&&i<10000;i++)
    {
        printf(" %ld ",mem[i]);
        if(i%10==0)
        printf("\n");

    }
    printf("-----------------\n");
    for(int i=1;f[i]!=0&&i<10000;i++)
    {
        printf(" %ld ",f[i]);
        if(i%10==0)
        printf("\n");

    }
    #endif
    return 0;

}

int walk2(int n,int k)
{
    int q;
    mem[1]=mem[0]=1;
    if(k>=2)
    {
        mem[2]=2;
    }
    else mem[2]=1;
    for(int i=3;i<=n;i++)
    {
        
            for(q=min(i,k);q>=1;q--)
            {
                mem[i]+=mem[i-q];
                if(mem[i]>=100003)mem[i]=mem[i]%100003;
            }
    }
    return mem[n];
}




int walk1(int n,int k){  
     for(int i=2;i<=n;i++) f[i]=0;
    f[1]=f[0]=1;
    for(int i=2;i<=n;i++){
        for(int j=min(i,k);j>=1;j--){
            f[i]+=f[i-j];
            if(f[i]>=100003) f[i]%=100003;        //注意取模！！！卡了我一次
        }
    }
    return 0;
}