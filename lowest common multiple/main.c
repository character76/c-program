#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    int c;
    int output;
    printf("input two number:");
    int input_num(int a,int b);
    scanf("%d %d",&b,&c);
    a=input_num(1997,615);
    output = b*c/a;
    printf("\n their  lowest common multiple is: %d",output);
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
