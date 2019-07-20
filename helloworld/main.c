#include <stdio.h>
#include <stdlib.h>

#define pie 3.1415926

int main()
{

    int max(int x,int y);
    int a,b,c;
    printf("input>>>");
    scanf("%d,%d",&a,&b);
    c = max(a,b);

    printf("Hello world!\n");
    printf("The biggest one among them is %d \n",c);
    printf("the");

    return 0;
}
int max(int x,int y)
{
    int z;
    if (x>y) z=x;
    else z=y;
    return (z);
}
int range(int input_num_1,int input_num_2)
{
    int a=10;


}
