#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input_num;
    int judge_prime(int input_num);
    int i;
    int coun=0;

    printf("input a number>>>");
    scanf("%d",&input_num);
    int num_list[3] = {0,-1,0};
    /*list位置3用来防止重复输出结果*/
    for (i=2;i<=input_num;i=i+1)
    {
        int a=0;
        a=judge_prime(i);
        if (a!=0&&coun==0)
        {
            num_list[0]=a;
            num_list[2]=1;
        };
        if (a!=0&&coun==1)
        {
            num_list[1]=a;
            num_list[2]=1;
        };

        if ((num_list[0]-num_list[1]==2 || num_list[1]-num_list[0]==2)&&num_list[2]==1)
        {
            printf("%d %d\n",num_list[0],num_list[1]);
            num_list[2]=0;
        };
        if (a!=0&&coun==0)
        {
            coun=1;
        }
        else if(a!=0)
        {
            coun=0;
        };
    }
    return 0;
}
int judge_prime(int input_num)
{
    int a;

    for (a=2;a<=(input_num/2);a=a+1)
    {
        if ((input_num%a)==0)
        {
            return 0;
        }
    }
    return input_num;
}

