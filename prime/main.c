#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int judge_prime(int);
    int prime;
    int r;
    scanf("%d",&prime);
    r = judge_prime(prime);
    if(r != 0)
    {
        printf("Yes");
    }
    else printf("No");
    return 0;
}
int judge_prime(int input_num)
{
    int a;

    for (a=2;a<=(sqrt(input_num));a=a+1)
    {
        if ((input_num%a)==0)
        {
            return 0;
        }
    }
    return input_num;
}
