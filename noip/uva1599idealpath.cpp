#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef struct{
    int nodes;
    int sum;
    int distance;
}rodes;

int n,m,x,y,v,bg,ed;
int** grap={NULL};
int rode[100000]={0},smallc[100000]={0},smalld[100000]={0};
int main()
{
    bool bfs(int ed);
    cin>>n,m;
    
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
        bfs(ed);
        cout<<smalld[bg]<<endl;
    
    
    
    return 0;
}
bool bfs(int ed)
{
    int colors;
    bool find=0;
    queue<rodes> node;
    rodes now;
    now.nodes=ed;
    now.sum=0;
    now.distance=0;
    node.push(now);
    while(!node.empty())
    {
        now=node.front();node.pop();
        if(now.nodes==bg)
        {
            find=1;
            
            break;
        }
        if(now.nodes==ed)
        break;
        for(int i=1;i<grap[now.nodes][0];i++)
        {
            if(grap[ed][i]!=0)
            {
                colors=grap[now.nodes][0];
                now.nodes=i;
                now.distance++;
                now.sum+=colors;
                node.push(now);
                if(smalld[i]==0)
                {
                    smalld[i]=now.distance;
                }
                if(smallc[i]==0)
                {
                    smallc[i]=now.sum;
                }
                if(smallc[i]!=0&&now.sum<smallc[i])
                {
                    smallc[i]=now.sum;
                }
            }
        }
    }
    if(find)
    {
        return true;
    }
    else return false;
    
}