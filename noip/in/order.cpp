#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#define __DEBUG__
using namespace std;
const int maxn=10010;
const int none=0;
char post_order[maxn],in_order[maxn],lch[maxn],rch[maxn];
int n=0;

char build(int x1,int y1,int x2,int y2)//in order post order
{
    if(x1>y1)return none;
    char root=post_order[y2];
    int p=x1;
    while(in_order[p]!=root)p++;
    int cnt=p-x1;
   printf("%c",root);
    build(x1,p-1,x2,x2+cnt-1);
    build(p+1,y1,x2+cnt,y2-1);
    return root;
}


int main()
{
    char build(int x1,int y1,int x2,int y2);//in order post order
    int root;
    scanf("%s",in_order);
    scanf("%s",post_order);
    n=strlen(in_order);
    #ifdef __DEBUG__
    cout<<n<<endl;
    #endif
    root=build(0,n-1,0,n-1);


    return 0;
}
