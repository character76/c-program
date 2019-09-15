#include<iostream>
#include<queue>
#define __DEBUG__

using namespace std;
typedef struct{
    int x;
    int y;
}point;
void bfs(int **p,int n,int x,int y);
void bfs_begin(int **p,int n);
int main()
{
    void print_s(int **p,int n);
    int n;
    int** p;
    cin>>n;
    p=new int* [n];
    for(int i=0;i<n;i++)
    {
        p[i]=new int[n];
        for(int q=0;q<n;q++)
        {
            cin>>p[i][q];
        }
    }
    #ifdef __DEBUG__
    cout<<"begin---"<<endl;
    #endif
    bfs_begin(p,n);
    print_s(p,n);
    return 0;
}
void bfs_begin(int **p,int n)
{
    int x,y,j=0;
    for(int i=0;i<n;i++)
    {
        for(int q=0;q<n;q++)
        {
            if(p[i][q]==0&&p[i-1][q]==1&&j==0)
            {
                x=i;
                y=q;
                j=1;
                break;
            }
        }
        if(j==1)break;
    }
    #ifdef __DEBUG__
        cout<<"begin:"<<x<<","<<y<<endl;
        #endif
    bfs(p,n,x,y);

}
void bfs(int **p,int n,int x,int y)
{
    queue<point> go;
    int now_x,now_y;
    point begin,now;
    begin.x=x;
    begin.y=y;
    p[x][y]==2;
    go.push(begin);
    while(!go.empty())
    {
        now=go.front();go.pop();
        now_x=now.x;
        now_y=now.y;
        #ifdef __DEBUG__
        cout<<"go:"<<now_x<<","<<now_y<<endl;
        #endif
        if(p[now_x-1][now_y]==0)
        {
            now.x=now_x-1;
            now.y=now_y;
            go.push(now);
            p[now_x-1][now_y]=2;
        }
        
        if(p[now_x][now_y+1]==0)
        {
            now.x=now_x;
            now.y=now_y+1;
            go.push(now);
            p[now_x][now_y+1]=2;
        }
        if(p[now_x+1][now_y]==0)
        {
            now.x=now_x+1;
            now.y=now_y;
            go.push(now);
            p[now_x+1][now_y]=2;
        }
        if(p[now_x][now_y-1]==0)
        {
            now.x=now_x;
            now.y=now_y-1;
            go.push(now);
            p[now_x][now_y-1]=2;
        }
    }
}
/*
  0
3 c 1
  2
*/

void print_s(int **p,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int q=0;q<n;q++)
        {
            cout<<p[i][q]<<" ";
        }
        cout<<endl;
    }
}