#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ex_gcd(int a,int b,int* x,int* y);
    int a,b,r;
    printf("enter a,b:");
    scanf("%d %d",&a,&b);
    int x=0,y=0;
    r=ex_gcd(a,b,&x,&y);
    printf("ans:%d,%d,greatest common divsor:%d",x,y,r);
    return 0;
}
int ex_gcd(int a,int b,int* x,int* y)
{
    printf("x:%d,*x:%d\n",x,*x);
    if (b ==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    int r=ex_gcd(b,a%b,x,y);
    int c=*x;
    *x=*y;
    *y=c-(a/b)*(*y);
    return r;
    

}

