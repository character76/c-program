#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,m,x,y,v,bg,ed;
int** grap={NULL};
int rode[100000]={0},smallc[100000]={0},smalld[100000]={0};
int main()
{
    while(cin>>n,m!=0)
    {
        grap=new int*[n];
        for(int i=0;i<n;i++)
        {
            grap[i]=new int[m];
        }
        memset(grap,0,sizeof(int)*n*m);
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>v;
            if(y>grap[x][0])
            grap[x][0]=y;
            if(grap[x][y]!=0)
            {
                if(v<grap[x][y])
                {
                    grap[x][y]=v;
                }
                else continue;
            }
        }
        cin>>bg>>ed;
    }
    
    return 0;
}
bool bfs(int ed)
{
    queue<int> node;
    int now=ed;
    node.push(ed);
    while(!node.empty())
    {
        now=node.front();node.pop();
        if(now==bg)
        {

            break;
        }
        if(now==ed)
        break;
        for(int i=1;i<grap[now][0];i++)
        {
            if(grap[ed][i]!=0)
            {
                node.push(i);
                if(smalld[i]==0)
                {
                    smalld[i]==v;
                }
            }
        }
    }
    
}