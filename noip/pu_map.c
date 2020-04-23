#include<stdio.h>
#include<stdlib.h>

int main()
{
    int is_on(int map[][7],int x,int y,int n);
    int n,x,y;
    int a,b,g,k;
    int map[10001][7]={0};
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int ii=0;ii<4;ii++)
        scanf("%d",&map[i][ii]);
    };
    scanf("%d %d",&x,&y);

    printf("%d",is_on(map,x,y,n));
    return 0;
}
int is_on(int map[][7],int x,int y,int n)
{
    int len=0,wid=0;
    int state=-1;
    for(int i=1;i<=n;i++)
    {
        wid=map[i][0]+map[i][2];
        len=map[i][1]+map[i][3];
        if(  ( (map[i][0]<x&&x<wid)||x==map[i][0]||x==wid) && ( (map[i][1]<y&&y<len)||y==len||y==map[i][1]) )
        {
            state=i;
        }

    }
    return state;
}

