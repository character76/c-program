#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int area(int a,int b, int c);
    printf("Hello world!\n");

    char areas = area(3,4,5);
    printf(areas);
    return 0;
}
int area(int a,int b,int c)
{
    int sum;
    double total;
    sum = a+b+c;
    double sum_f = sum*(sum-a)*(sum-b)*(sum-c);
    total = pow(sum_f,0.5);
    return total;
}
