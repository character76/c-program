#include <iostream>
#define INF 100000
using namespace std;
int d[200][200]={0};
int main()
{
    int l1,l2;
    cin>>l1>>l2;
    int* a1=new int[l1+1]();
    int* a2=new int[l2+1]();
    for(int i=1;i<=l1;i++)
    {
        cin>>a1[i];
    }
    for(int i=1;i<=l2;i++)
    {
        cin>>a2[i];
    }
    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(a1[i]==a2[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    cout<<d[l1][l2];
    return 0;

}
int rdfs(int* a1,int* a2,int l1,int l2,int i1,int j2)
{
    if(d[i1][j2]!=0)
    return d[i1][j2];
    if(a1[i1]==a2[j2])
    {
        return d[i1][j2]=d[i1-1][j2-1]+1;
    }
    return d[i1][j2]=max(rdfs(a1,a2,l1,l2,i1-1,j2),rdfs(a1,a2,l1,l2,i1,j2-1));
}