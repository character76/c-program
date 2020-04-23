#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
int ob[26][2]={0};
int main()
{
    int find(int v);
    int ind;
    
    cin>>n>>m;
    int** d=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        d[i]=new int[n+1]();
    }
    for(int i=1;i<=m;i++)
    {
        cin>>ob[i][0]>>ob[i][1];
        
        for(int j=0;j<=n;j++)
        {
            d[i][j] = (i==1 ? 0 : d[i-1][j]);
            if(j>=ob[i][0])
            {
                d[i][j]=max(d[i][j],d[i-1][j-ob[i][0]]+ob[i][0]*ob[i][1]);
            }
        }
        if(i==m)
        {
            cout<<d[i][n]<<endl;
            return 0;
        }
    }
    cout<<d[m+1][n];
    return 0;
}
/*int find(int v)
{
    
    for(int i=m;i>=1;i--)
    {
        for(int j=0;j<=v;j++)
        {
            d[i][j] = (i==0 ? 0:d[i+1][j]);
            if(j>=ob[j][0])
            {
                d[i][j]=max(d[i][j],d[i+1][j-ob[j][0]]+ob[j][0]*ob[j][1]);
            }
        }
    }
    return maxv[v];
}*/