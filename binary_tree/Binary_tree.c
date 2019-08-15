#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int data;
    int depth;
    struct Binary* left;
    struct Binary* right;
}Binary;

int main()
{
    
    return 1;
};

Binary* create_tree(Binary* begin_point,int depth)
{
    begin_point=malloc(sizeof(Binary));
    if(depth==0)
    {
        begin_point[0].left=NULL;
        begin_point[0].right=NULL;
        return begin_point;
    }
    begin_point[0].left=create_tree(begin_point[0].left,depth-1);
    begin_point[0].right=create_tree(begin_point[0].right,depth-1);
    return begin_point;
};
Binary* free_tree(Binary* begin_point)
{
    if(begin_point[0].left)
    {
        
    }
}
int print_tree(Binary* begin,int depth,int* data)
{
    if(begin[0].left==NULL||begin[0].right==NULL)
    {
        
    }
}
