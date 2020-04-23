#include <iostream>
#include <algorithm>
#include <cstring>
#include<cstdio>

using namespace std;
int ap[65]={0};
int* lens;int* vis;
int n;
int maxs=-100000;
int main()
{
    int dfs(int before,int k,int rest);
    int a,total=0,sum=0,ans;
    cin>>n;
    lens=new int[n];
    vis=new int[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a<=50)
        {
            lens[i]=a;
            ap[a]++;
            if(a>maxs)
            maxs=a;
            total++;
            sum+=a;
        }
        if(a>50)i--;
        
    }
    sort(lens,lens+n);
    memset(vis,-1,sizeof(int)*n);

    for(int i=a;i<sum;i++)
    {
        if(i>sum/2)
        {
            ans=sum;
            printf("%d",ans);
            return 0;
        }
        if(i<=sum/2)
        {
            int times=0,out,check=0;
            for(int j=n-1;j>=0;j--)
            {
                if(vis[j]==-1&&(i-lens[j]>=0)&&check==0)
                {
                    #ifdef __DEBUG__
                        cout<<"is handing:"<<lens[j]<<endl;
                        #endif
                    vis[j]=1;
                    out=dfs(j,2,i-lens[j]);
                    if(out!=-1)
                    {
                        #ifdef __DEBUG__
                        cout<<endl;
                        #endif
                        vis[out]=1;
                        times++;
                    }
                    else 
                    {
                        check=1;
                        vis[j]=-1;
                    }
                }
                else if(check==1&&vis[j]==-1&&(i-lens[j]>=0)&&vis[j]!=vis[j+1])
                {
                    vis[j]=1;
                    out=dfs(j,2,i-lens[j]);
                    if(out!=-1)
                    {
                        #ifdef __DEBUG__
                        cout<<endl;
                        #endif
                        vis[out]=1;
                        times++;
                        check=0;
                    }
                    else 
                    {
                        check=1;
                        vis[j]=-1;
                    }
                }
            }
            #ifdef __DEBUG__
                cout<<" sum:"<<i<<" "<<endl;
            #endif
            for (int q = 0; q < n; q++)
            {
                #ifdef __DEBUG__
                cout<<" "<<vis[q]<<" ";
                #endif
                if(vis[q]==-1)
                {
                    times=-1;
                    
                }
                vis[q]=-1;
                
            }
            #ifdef __DEBUG__
                cout<<endl;
                #endif
            if(times!=-1)
            {
                cout<<i;
                return 0;
            }
            
            
        }
    }
    cout<<ans;
    return 0;
}
int dfs(int before,int k,int rest)
{vis[before]=1;
    if(rest==0)
    {
        vis[before]=1;
        return before;
    }
    int s=0;
    for(int i=n-1;i>=0;i--)
    {
        s=0;
        if(vis[i]==-1&&rest-lens[i]==0)
        {
            vis[i]=1;
            #ifdef __DEBUG__
                cout<<"used: "<<lens[i];
                #endif
            return i;
        }
        else if(vis[i]==-1)
        {
            if(rest-lens[i]>=0)
            {
                s=dfs(i,k+1,rest-lens[i]);
                if(s!=-1)
                {
                    #ifdef __DEBUG__
                    cout<<"used: "<<lens[i];
                    #endif
                    vis[s]=1;
                    return s;
                }
            }
        }
    }
    vis[before]=-1;
    return -1;
}