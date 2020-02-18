#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;
int n,m;
int d[501][501];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (i!=j) {
                d[i][j] = INF;
            }else {
                d[i][j] = 0;
            }
        }
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    bool flag[501];
    memset(flag,true,sizeof(flag));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (d[i][j]==INF && d[j][i]==INF){
                flag[i]= false;
                break;
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(flag[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}