#include <stdio.h>
#include <stdlib.h>

int catch_drop(int *p,int length);

int main()
{
    int a[] = {91,2,3,5,90};
    int *p;
    p = &a[0];
    int c;
    c = catch_drop(p,5);
    printf("%d\n",c);
    return 0;
}
int catch_drop(int *p,int length)
{
    int index = 0;
    for (int i=1;i<=length-1;i++)
    {
        if(*(p+i)>*(p+index))
        {
            index = i;
        }
    }
    return index;
}

