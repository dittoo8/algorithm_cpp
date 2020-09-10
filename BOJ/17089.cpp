#include <iostream>
#define MAX 4001
using namespace std;
int n,m;
bool friends[MAX][MAX];
int friend_cnt[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int answer = -1;
    int u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        friends[u][v] = true;
        friends[v][u] = true;
        friend_cnt[u]++;
        friend_cnt[v]++;
    }
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(!friends[i][j]) continue;
            for(int k=j+1;k<=n;k++){
                if(friends[j][k] && friends[i][k]){
                    int temp = friend_cnt[i] + friend_cnt[j] + friend_cnt[k] - 6;
                    if (answer == -1 | answer > temp) answer = temp;
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}