#include <iostream>
using namespace std;
int d[101][1001],a[101];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,s,m;
    cin >> n >> s >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    d[0][s] = true;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m;j++){
            if (d[i][j]==false) continue;
            if (j-a[i+1] >= 0) d[i+1][j-a[i+1]] = true;
            if (j+a[i+1] <= m) d[i+1][j+a[i+1]] = true;
        }
    }
    int ans = -1;
    for(int i=m;i>=0;i--){
        if(d[n][i]) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}