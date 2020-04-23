#include<iostream>
using namespace std;
int main()
{
    int m,s,t,d=0;
    cin>>m>>s>>t;
    for(int i=1;i<=t;i++)
    {
        if(m>10)
        {
            m-=10;
            d+=17;
        }
        else if(m<10)
        {
            int j;
            for(j=0;(m+j*4)>10;i++);
            m+=j;
        }

    }
    return 0;
}

