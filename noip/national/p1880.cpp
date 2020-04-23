#include <iostream>
using namespace std;
int main()
{
    int n;
    int *stones=new int[n*2-1];
    int *sum=new int[n+1]();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>stones[i];
        stones[2*n-i]=stones[i];
        sum[i]=sum[i-1]+stones[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            
        }

    }
    return 0;
}
