#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double perimeter(int a, int b, int c);
    double area = perimeter(12,5,13);
    printf("areas =%f",area);
    return 0;
}

double perimeter(int a,int b,int c)
{

    int p= (a+b+c)/2;
    double total = p*(p-a)*(p-b)*(p-c);
    return sqrt(total);
}
