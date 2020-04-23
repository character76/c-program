#include <iostream>
#include <vector>
using namespace std;
int search[200][200];
int have[100];
int main()
{   

    return 0;
}

int cut(int n,int k)
{
    for(int i=1;i<=(n/2);i++)
    {
        if(have[i]!=1)
        {
            cut(n-i)
        }
        
    }
}