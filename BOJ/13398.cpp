#include <iostream>
#include <algorithm>
using namespace std;
int a[100002];
int d[100002][2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    d[1][0] = a[1];
    d[1][1] = a[1];
    for(int i=2;i<=n;i++){

        d[i][0] = max(d[i-1][0] + a[i], a[i]);
        d[i][1] = max(d[i-1][0], d[i-1][1] + a[i]);
    }
    int res = -2147000000;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            res = max(d[i][j], res);
        }
    }
    cout << res <<endl;
    return 0;
}