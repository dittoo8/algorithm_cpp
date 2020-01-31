#include <iostream>
#include <vector>
#define MAX 1002
using namespace std;
int n,m;
int w[MAX];
vector<int> p[MAX];
bool check[MAX];
bool dfs(int x){
    for(int i=0;i<p[x].size();i++){
        int y = p[x][i];
        if (check[y]) continue;
        check[y] = true;
        if(w[y]==0 || dfs(w[y])) {
            w[y] = x;
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
            p[i].push_back(b);
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        fill(check,check+MAX, false);
        if (dfs(i)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}