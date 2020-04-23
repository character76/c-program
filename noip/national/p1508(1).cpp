#include <iostream>
#include <cstring>
#define INF 100000
using namespace std;

int main()
{
    int m,n,maxf=-INF;
    cin>>m>>n;
    
    
    int* input=new int[n]();
    int* maxv=new int[n]();
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>input[j];
        }
        for(int j=0;j<n;j++)
        {
            for(int p=-1;p<=1;p++)
            {
                if(j+p>=0&&j+p<=n)
                {
                    if(input[j+p]>maxf)
                    maxf=input[j+p];
                }

            }
            maxv[j]+=maxf;
            maxf=-INF;
        }
    }
    cout<<maxv[n/2];

    return 0;
}