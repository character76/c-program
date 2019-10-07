#include <iostream>
using namespace std;
int m,s,t;
int main()
{
    cin>>m>>s>>t;
    int m1=m;
    int i;
    int dis1=0,dis2=0;
    int t1=0;
    while(dis1<s&&dis2<s)
    {
        if(m>=10)
        {
            dis1+=60;
            dis2+=17;
            t1++;
            m-=10;

        }
        else 
        {
            for(i=1;(m+(i*4))<10;i++);
            dis2+=i*17;
            m+=i*4;
            t1+=i;
        }
        if(dis2>dis1)
        {
            dis1=dis2;
            m=m1;
        }

    }
    if(t1>t)
    {
        cout<<"No"<<endl;
        cout<<max(dis1,dis2);
    }
    else 
    {
        cout<<"Yes"<<endl;
        cout<<t1;
    }
    return 0;
}