#include <iostream>
#include <vector>
using namespace std;
int n,m,h;
int a[100][100];
int ans = -1;
vector<pair<int, int> > v;
int start(int c){
    int r = 1;
    while(r <=h){
        c+=a[r][c];
        r++;
    }
    return c;
}
bool go(){
    for(int i=1;i<=n;i++){
        int res = start(i);
        if (res != i) return false;
    }
    return true;
}
void solve(int idx,int cnt){
    if(cnt >3) return;
    for(int i=idx;i<v.size();i++){
        int x = v[i].first;
        int y = v[i].second;
        if(a[x][y]!=0 || a[x][y+1]!=0) continue;
        a[x][y] = 1;
        a[x][y+1] = -1;
        if( go()){
            if (ans == -1 || ans > cnt){
                ans = cnt;
            }
        }else solve(i+1, cnt+1);
        a[x][y] = 0;
        a[x][y+1] = 0;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> h;
    int x, y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        a[x][y]= 1;
        a[x][y+1]= -1;
    }
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n-1;j++){
            if(a[i][j]!=0) continue;
            if(a[i][j+1]!=0) continue;
            v.push_back(make_pair(i,j));
        }
    }
    if (go()){
        cout << 0 << '\n';
        return 0;
    }
    solve(0,1);
    cout << ans << '\n';
    return 0;
}