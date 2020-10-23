#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int dist[101][101] = {0};
    int n,m,u,v,c;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        cin >> u >> v >> c;
        if (dist[u][v] == 0){
            dist[u][v] = c;
        }else {
            if(dist[u][v]>c){
                dist[u][v] = c;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dist[i][k]==0) continue;
            for(int j=1;j<=n;j++){
                if (dist[k][j]==0 || i ==j) continue;
                if (dist[i][j]==0 || dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << dist[i][j]<<' ';
        }
        cout << '\n';
    }
    return 0;
}