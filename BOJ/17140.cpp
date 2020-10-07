#include <iostream>
#include <queue>
using namespace std;
int r,c,k,n=3,m=3;
int cnt[101], a[101][101];
void solve(){
    for(int t=0;t<101;t++){
        if(a[r][c] == k ){
            cout << t << '\n';
            return;
        }
        if(n>=m){ //행연산
            for(int i=1;i<=n;i++){
                priority_queue<pair<int, int> > pq;
                fill(&cnt[0], &cnt[100]+1,0);
                for(int j=1;j<=m;j++){
                    if(a[i][j]){
                        cnt[a[i][j]]++;
                        a[i][j] = 0;
                    }
                }
                for(int j=1;j<=100;j++){
                    if(cnt[j]) {
                        pq.push(make_pair(-cnt[j],-j));
                    }
                }
                int len = pq.size()*2;
                m = max(m,len);
                for(int j=1;j<=len;j+=2){
                    a[i][j] = -pq.top().second;
                    a[i][j+1] = -pq.top().first;
                    pq.pop();
                }
            }
        }else {
            for(int i=1;i<=m;i++){
                priority_queue<pair<int, int> > pq;
                fill(&cnt[0], &cnt[100]+1,0);
                for(int j=1;j<=n;j++){
                    if(a[j][i]){
                        cnt[a[j][i]]++;
                        a[j][i] = 0;
                    }
                }
                for(int j=1;j<=100;j++){
                    if(cnt[j]) {
                        pq.push(make_pair(-cnt[j],-j));
                    }
                }
                int len = pq.size()*2;
                n = max(n,len);
                for(int j=1;j<=len;j+=2){
                    a[j][i] = -pq.top().second;
                    a[j+1][i] = -pq.top().first;
                    pq.pop();
                }
            }
        }
    }
    cout << -1 << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}