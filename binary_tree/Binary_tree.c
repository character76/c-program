#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int value;
    struct Binary* left;
    struct Binary* right;
}Binary;

int main()
{
    
    Binary* tree_init();

    return 1;
};
Binary* tree_init()
{
    Binary* head_node;
    head_node=caloc(1,sizeof(Binary));
    head_node->left=NULL;
    head_node->right=NULL;
    head_node->value=65565;
}

void free_tree(Binary* node)
{
    if(node==NULL)
    {
        return NULL;        
    }
    if(node!=NULL)
    {
        Binary* next_l=free_tree(node->left);
        free(next_l);

        Binary* next_r=free_tree(node->right);
        free(next_r);
    }
    
}
Binary* create_node(Binary* node)
{
    if(node==NULL)
    {
        node=malloc(sizeof(Binary));
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    else return NULL;
}
Binary* tree_insert(Binary* node,int key)
{
    Binary* next_node;
    if(node->value==key)
    return node;
    if(node->value>key&&node->right==NULL)
    {
        next_node=create_node(node->left);
        return next_node;
    }
    else if(node->value>key&&node->right!=NULL)
    {
        return tree_insert(node->left,key);
    }
    if(node->value<key&&node->left==NULL)
    {
        next_node=create_node(node->right);
        return next_node;
    }
    else if(node->value<key&&node->left!=NULL)
    {
        return tree_insert(node->right,key);
    }
    else return NULL;
}
int print_tree(Binary* begin,int depth,int* data)
{
    if(begin[0].left==NULL||begin[0].right==NULL)
    {
        
    }
}
