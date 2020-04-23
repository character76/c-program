#include <iostream>
using namespace std;
#define __DEBUG__
int grap[500][5000]={0};
int* graps[1000]={NULL};
const int maxni=2000000;
int n,m,count,x,y,v,start,endp,cmin=maxni,cmax=maxni,nans,before;//mans the maxn ans
float mans=maxni;
int search_help(int x,int maxcost,int mincost);
int gcd(int a,int b);
int main()
{
    
    bool search(int x);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>v;
        if(y>grap[x][0])
        grap[x][0]=y;//标记位 防过度历遍
        
        if(grap[x][y]!=0)
        {
            if(grap[x][y]>0)
            {
                before=grap[x][y];
                grap[x][y]=(-2);
                graps[x]=new int [3];
                graps[x][0]=2;
                graps[x][1]=before;
                graps[x][2]=v;
                #ifdef __DEBUG__
                cout<<"extra route add "<<grap[x][y]<<endl;
                #endif
                continue;
            }
            else
            {
                grap[x][y]--;
                graps[x][0]++;
                graps[x]=new int [graps[x][0]];
                graps[x][graps[x][0]]=v;
                #ifdef __DEBUG__
                cout<<"extra route:"<<x<<"  "<<y<<"cost: "<<v<<endl;
                #endif
                continue;
            }
            

        }
        grap[x][y]=v;
    }
    cin>>start>>endp;
    if(!search(start))
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        #ifdef __DEBUG__
            cout<<"ans:";
            #endif
        if(cmax%cmin==0)
        {
                cout<<mans<<endl;
                return 0;
        }
        else
        {
            int r=gcd(cmax,cmin);
            #ifdef __DEBUG__
            cout<<"gcd ans:"<<r<<"   ";
            #endif
            cout<<cmax/r<<"/"<<cmin/r<<endl;
        }
        }
    return 0;
}
int gcd(int a,int b) {while(b^=a^=b^=a%=b);return a;}
bool search(int x)
{
    
    for(int i=1;i<=grap[x][0];i++)
    {
        if(grap[x][i]>0)
        {
            search_help(i,grap[x][i],grap[x][i]);
            #ifdef __DEBUG__
            cout<<"begin from:";
            #endif
        }
        if(grap[x][i]<0)
        {
            #ifdef __DEBUG__
            cout<<"read extra route"<<graps[x][1]<<endl;
            #endif
            for(int q=1;q<=(-grap[x][i]);q++)
            search_help(i,graps[x][q],graps[x][q]);
            
        }
    }
    if(mans==maxni)
    {
        return false;
    }
    else return true;
    

}
int search_help(int x,int maxcost,int mincost)
{
    if(x==endp)
    {
        float ans=float(maxcost)/float(mincost);
        if(ans<=mans)
        {
            mans = ans;
            cmin=mincost;
            cmax=maxcost;
        }
        #ifdef __DEBUG__
            cout<<"end with:"<<maxcost<<" and "<<mincost<<endl;
        #endif
        return 1;
    }
    if(x!=endp)
    {
        nans=float(maxcost)/float(mincost);
        if(nans>=mans&&nans!=1)return -1;
        for(int i=1;i<=grap[x][0];i++)
        {
            if(grap[x][i]>0)
            {
                if(grap[x][i]>maxcost)
                {
                search_help(i,grap[x][i],mincost);
                }
                else if(grap[x][i]<mincost)
                {
                search_help(i,maxcost,grap[x][i]);
                }
                else search_help(i,maxcost,mincost);
            }
        if(grap[x][i]<0)
        {
            #ifdef __DEBUG__
            cout<<"read extra route"<<graps[x][1]<<endl;
            #endif
            for(int q=1;q<=(-grap[x][i]);q++)
            {
                if(graps[x][q]>maxcost)
                {
                search_help(i,graps[x][q],mincost);
                }
                else if(graps[x][q]<mincost)
                {
                search_help(i,maxcost,graps[x][q]);
                }
                else search_help(i,maxcost,mincost);

            }
            
            
        }
        }
    }
}

