#include <stdio.h>
#include <stdlib.h>

int main()
{
    void split_int(int *arr,int ink,int left);
    int n;
    printf("Hello world!\n");
    scanf("%d",&n);
    int *situation=malloc(sizeof(int)*n);
    split_int(situation,0,n);
    /*
    Here comes an interesting thing ,if we change '0' here into '1' it will still work but will print arr's address on the first one
    and it won't overflow while running.
    */
    return 0;
}
void print_int(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void split_int(int *arr,int ink,int left)
{
    if(left==0)
    {
        print_int(arr,ink);
        return;
    }
    for(int i=1;i<=left;i++)
    {
        arr[ink]=i;
        split_int(arr,ink+1,left-i);
    }

}

