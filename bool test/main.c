#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
bool judge(int num);
int main()
{
    printf("Hello world!\n");
    if(judge(100))
    {
        printf("true");
    }
    return 0;
}
bool judge(int num)
{
    if (num>0)return true;
    if (num<0)return false;
    return false;
}
