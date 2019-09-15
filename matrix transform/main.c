#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
This prog is for square matrix multiply
*/
int main()
{
    return 0;
}
int** multiply(int **a,int **b,int len)//default is to take a&&b as a square
{
    //create ans matrix
    int** m_matrix(int len);
    int**ans= m_matrix(len);
    int *column_b=calloc(sizeof(int)*len);
    for(int i=0;i<len;i++)//row
    {
        for(int q=0;q<len;q++)//column
        {
            ans[i][q]
        }
    }
}
int det(int **a,int len)
{

}

int** m_matrix(int len)
{
    int** a=malloc(sizeof(int)*len);
    for(int i=0;i<len;i++)
    {
        a[i]=malloc(sizeof(int)*len);
    }
    return a;
}

int v_multiple(int *a,int *b,int len,int* b_column,int state)//vector multiply
{

    int sum=0;
    switch (state){
        case 0://for a's row vector* b's column vector
            for(int i=0;i<len;i++)
            {
                sum+=a[i]*(*(b_column+i*len));
            }
        break;
        case 1:
            for(int i=0;i<len;i++)
            {
                
            }
        break;
        default:
        return 65565;
    }
    return sum;
}