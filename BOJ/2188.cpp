#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> c[202];
int h[202];
bool check[202];
bool dfs(int now){
    for(int i=0;i<c[now].size();i++){
        int y = c[now][i];
        if (check[y]) continue;
        check[y] = 1;
        if(h[y]==0 || dfs(h[y])) {
            h[y] = now;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        while(a--){
            int b;
            cin >> b;
            c[i].push_back(b);
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        //전체 소의 값으로 for문
        fill(check, check+ 202, false);
        if(dfs(i)) cnt++;
    }
    cout << cnt <<endl;
    return 0;
}