#include <cstdio>
int a[100005];
void init(){
    a[0]=a[1]=1;
    for(register int i=2;i<=k;i++)
        a[i]=(2*a[i-1])%100003;
}
int walk1(int n,int k){  
    init();
    for(register int i=k+1;i<=n;i++) a[i]=(2*a[i-1]+100003-a[i-1-k])%100003;
    return a[n];
}