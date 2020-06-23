#include <iostream>
using namespace std;
int  a[31][31];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if (j==1 || j ==i) a[i][j] = 1;
            else a[i][j] = a[i-1][j-1]+a[i-1][j];
        }
    }
    cout << a[n][k] << '\n';
    return 0;
}