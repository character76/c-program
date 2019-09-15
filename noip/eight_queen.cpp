#include <cstdio>
#include <cstring>

int n;
int places=0;
using namespace std;
void print_s(int* cb);
bool is_ok(int row,int* cb);
int main()
{
    int* column;
    void queens(int row,int *cb);
    scanf("%d",&n);
    column=new int[n];
    memset(column,0,sizeof(int)*n);
    queens(0,column);
    printf("%d",places);
    return 0;
}
inline void queens(int row,int* cb)
{
    if(row==n)
    {
        places++;
        if(places<=3)
        print_s(cb);
        return;
    }
    else{
    for(int i=0;i<n;i++)
    {
        cb[row]=i;
        if(is_ok(row,cb))
        {
            queens(row+1,cb);   
        }

    }
    }
}
bool is_ok(int row,int* cb)
{
    for(int i=row-1;i>=0;i--)
    {
        if(cb[row]==cb[i]||(cb[row]-cb[i]==row-i)||(cb[row]-cb[i]==i-row))
        {
            return false;
        }
    }
    #ifdef __DEBUG__
            printf("true");
            #endif
    return true;
}

void print_s(int* cb)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",cb[i]+1);
    }
    printf("\n");
}