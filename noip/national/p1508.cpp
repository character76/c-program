#include <iostream>
using namespace std;
int a[1005][1005];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            a[i][j]+=max(a[i-1][j-1],max(a[i-1][j],a[i-1][j+1]));
        }
    }
    cout<<max(a[n][m/2],max(a[n][m/2+1],a[n][m/2+2]));
    return 0;
}