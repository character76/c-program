#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 1;
    double x1,x2;

    int judge(int a,int b,int c);
    double delta = judge(a,b,c);
    if (delta != -1)
    {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);
        if (x1==x2)
        {
            printf("the solution of the equation is %f",x1);
        }
        else
        {
            printf("the solution of the equation is %f,%f",x1,x2);
        }

    }
    else
    {
        printf("no solution");
    }

    return 0;
}

int judge(int a,int b, int c)
{
    double delta = b*b-4*a*c;
    if(delta>0)
    {
        return delta;
    }
    else if(delta==0)
    {
        return delta;
    }
    else
    {
        return -1;
    }
    return 0;
}
