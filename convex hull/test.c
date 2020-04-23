#include<stdlib.h>
#include<stdio.h>
typedef struct {
    int x;
    int y;
    int state;
}Point;

int main()
{
    float slope(Point a,Point b);
    Point a,b;
    a.x=8;
    a.y=9;
    b.x=5;
    b.y=7;
    printf("slope %f",slope(a,b));
    return 1;
}
float slope(Point a,Point b)
{
    float delta_x=a.x-b.x;
    float delta_y=a.y-b.y;
    return delta_y/delta_x;
}