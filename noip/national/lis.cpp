#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--)
    {

    }
    return 0;
}
int bsearch(int* a,int n,int key)
{
    int l=0,r=n-1;
    int bg=n/2;
    while(a[bg]!=key)
    {
        if(a[bg]>key)
        {
            bg=
        }
    }
    return bg;
}