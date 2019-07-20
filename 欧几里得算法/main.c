#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Hello world!\n");
    int input_num(int a,int b);
    a=input_num(60,30);
    printf("%d",a);
    return 0;
}
int input_num(int a,int b)
{
    if (a%b !=0)
    {
        input_num(b,a%b);
    }
    else if(a%b==0)
    {
        return b;
    }
}
