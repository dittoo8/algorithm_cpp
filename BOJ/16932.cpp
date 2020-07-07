#include <iostream>
#include <set>
using namespace std;
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
int n,m,cnt,id,ans;
int map[1001][1001];
int idx[1001][1001], idxcnt[100001];
bool range(int x, int y){
    return x >= 0 && x < n  && y >= 0 && y <m;
}
void dfs(int x,int y){
    cnt++;
    idx[x][y]=id;
    for(int k=0;k<4;k++){
        int nx = x+dx[k], ny = y+dy[k];
        if (!range(nx,ny)) continue;
        if (idx[nx][ny] || map[nx][ny]==0) continue;
        dfs(nx,ny);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set<int> st;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (map[i][j]==0) continue;
            if (idx[i][j]) continue;
            cnt=0;
            id++;
            dfs(i,j);
            idxcnt[id]= cnt;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==1) continue;
            st.clear();
            int tmp =1;
            for(int k=0;k<4;k++){
                int nx = i+dx[k], ny = j+dy[k];
                if (!range(nx,ny)) continue;
                st.insert(idx[nx][ny]);
            }
            for(auto it = st.begin(); it != st.end(); it++){
                tmp+=idxcnt[*it];
            }
            if(tmp>ans) ans = tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}