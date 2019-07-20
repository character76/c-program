#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numsize;
    scanf("%d",&numsize);
    int *p = malloc(sizeof(int)*numsize);
    int  a[2] = {0,999999999};
    for(int i=0;i<numsize;i++)
    {
        scanf("%d",(p+i));
        if(*(p+i)>a[0])
        {
            a[0] = *(p+i);
        };
        if(*(p+i)<a[1])
        {
            a[1] = *(p+i);
        }
    }
    printf("%d,%d",a[1],a[0]);

    return 0;
}
