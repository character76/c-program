#include <iostream>
#include <algorithm>
using namespace std;
int ap[65]={0};
int* lens,vis;
int maxs=-100000;
int main()
{
    int n,a,total=0,sum=0,ans;
    cin>>n;
    lens=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a<=50)
        {
            lens[i]=a;
            ap[a]++;
            if(a>maxs)
            maxs=a;
            total++;
            sum+=a;
        }
        if(a>50)i--;
        
    }
    sort(lens,lens+n-1);
    cout<<lens[0];
    for(int i=a;i<sum;i++)
    {
        if(i>sum/2)
        {
            ans=sum;
            break;
        }
        if()
    }
    return 0;
}
bool dfs(int before,int ,int rest)
{
    
}