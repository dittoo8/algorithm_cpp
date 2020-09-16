#include <iostream>
#include <set>
#define MAX 1001
using namespace std;
int n,m,idx=1,cnt;
const int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};
bool visit[MAX][MAX];
int a[MAX][MAX];
int a_cnt[1000000];
void dfs(int x, int y){
    cnt++;
    visit[x][y]= true;
    a[x][y] = idx;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx < 0 ||nx>=n || ny < 0 || ny >= m) continue;
        if (a[nx][ny]==0) continue;
        if (visit[nx][ny]) continue;
        dfs(nx,ny);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j] && !visit[i][j]){
                cnt = 0;
                dfs(i,j);
                a_cnt[idx] = cnt;
                idx++;
            }
        }
    }

    set<int> st;
    int answer = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (a[i][j]==0){
                int temp = 0;
                st.clear();
                for(int k=0;k<4;k++){
                    int nx = i+dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny <0 || ny >= m) continue;
                    if (st.find(a[nx][ny])!=st.end()) continue;
                    st.insert(a[nx][ny]);
                    temp+=a_cnt[a[nx][ny]];
                }
                if (temp > answer) answer = temp;
            }
        }
    }
    cout << answer+1 << '\n';
    return 0;
}