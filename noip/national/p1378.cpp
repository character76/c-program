#include <iostream>
#include <cmath>
#define INF 100000;
#define PI 3.14;
using namespace std;
int n,bx1,by1,bx2,by2;
int marea,maxss=-INF;

struct Point{
    int x;
    int y;
    int r;
    bool is_expand;
    Point(int x1=0,int y1=0)
    {
        x=x1;
        y=y1;
        r=0;
        is_expand=false;
    }
    int get_distance(int x2,int y2)//square
    {
        if(is_expand)
        {
            int distance=(x2-x)*(x2-x)+(y2-y)*(y2-y);
            return (distance-r*r);
        }
        else return 0;
    }
};
/*inline int abs(int a)
{
    return (a>=0 ? a:-a);
}*/
int dfs_help(Point nowpoint,int expanded);
int main()
{
    Point* pset;
    int x,y;
    cin>>n;
    pset=new Point[n];
    cin>>bx1>>by1>>bx2>>by2;
    marea=abs((bx1-bx2)*(by1-by2));
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        pset[i].x=x;
        pset[i].y=y;
    }

    return 0;
}
int dfs(Point* pset)
{
    int area;
    int maxarea=-INF;
    if(n==0)
    return marea;
    for(int i=0;i<n;i++)
    {
        dfs_help(pset,pset[i],0,marea);
    }
    return maxarea;
}
int dfs_help(Point* pset,Point nowpoint,int expanded,int narea)
{

    //expanding
    if(expanded==0)
    {
        nowpoint.r=min(abs(nowpoint.x-bx1),abs(bx2-nowpoint.x),
        min(abs(nowpoint.y-by1),abs(by2-nowpoint.y)));
        nowpoint.is_expand=true;
        float area=float(marea)-(nowpoint.r)*(nowpoint.r)*PI;
        for(int i=0;i<n;i++)
        {
            if(pset[i].is_expand!=true)
            {
                dfs_help(pset,pset[i],expanded+1,area);
            }
        }
    }
    else if(expanded>=n)
    {
        if(narea>maxss)
        {
            maxss=narea;
        }
        return;
    }
    else
    {

        for(int i=0;i<n;i++)
        {
            if(pset[i].is_expand&&(pset[i].get_distance(nowpoint.x,nowpoint.y)<(pset[i].r*pset[i].r)))
            {
                return;
            }
            else(pset[i].is_expand)
            {
                r=sqrt(pset[i].get_distance(nowpoint.x,nowpoint.y))-(pset[i].r*pset[i].r);
            }
        }
    }
}