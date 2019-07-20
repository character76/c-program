#include <stdio.h>
#include <stdlib.h>

void change_direct_right(int *p,int length,int wide);
void change_direct_left(int *p,int length,int wide);

int a[3][3] = {0};
int b[3][3] = {0};

int main()
{

    int *p = &a[0][0];
    int *f = &b[0][0];
    printf("input the array:\n");
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",p+i*3+j);
        }
    }
    printf("scanf down!\n");
    change_direct_left(p,3,3);
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%-2d ",*(f+i*3+j));
        }
        printf("\n");
    }
    printf("turn right\n");
    change_direct_right(p,3,3);
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%-2d ",*(f+i*3+j));
        }
        printf("\n");
    }


    return 0;
}
void change_direct_right(int *p,int length,int wide)
{
    int length_index = length-1;
    for (int i=0;i<wide;i++)
    {
        for (int j=0;j<=length_index;j++)
        {
            b[i][length_index-j]=*(p+j*3+i);
        }
    }
    return;
}
void change_direct_left(int *p,int length,int wide)
{
    int length_index=length-1;
    for (int i=0;i<wide;i++)
    {
        for (int j=length_index;j>=0;j--)
        {
            b[j][i]=*(p+i*length+(length_index-j));
        }
    }
    return;
}

void change_up_down(int *p,int length,int wide)
{
    for (int i=0; i<length;i++)
    {
        printf("%d",i);
    }
    return;
}
