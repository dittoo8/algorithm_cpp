#include <iostream>
#include <vector>
#define MAX 52
using namespace std;
int n;
long long s[MAX][3];
vector<int> a[MAX];
bool check[MAX];
long long d[MAX];
bool dfs(int x){
    for(int i=0;i<a[x].size();i++){
        int y = a[x][i];
        if (check[y]) continue;
        check[y] = 1;
        if(d[y]==0 || dfs(d[y])){
            d[y] = x;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        s[i][0] = a;
        s[i][1] = b;
        s[i][2] = c;
    }
    for(int i=1;i<=n-1;i++){
        for(int j= i+1;j<=n;j++){
            if(s[i][0] == s[j][0] && s[i][1] == s[j][1] && s[i][2] == s[j][2]){
                a[i].push_back(j);
            } else if(s[i][0] >= s[j][0] && s[i][1] >= s[j][1] && s[i][2] >= s[j][2]){
                a[i].push_back(j);
            } else if(s[i][0] <= s[j][0] && s[i][1] <= s[j][1] && s[i][2] <= s[j][2]){
                a[j].push_back(i);
            }
        }
    }
    int cnt = n;
    for(int j=0;j<2;j++){
        for(int i=1;i<=n;i++){
            fill(check, check+MAX, false);
            if (dfs(i)) cnt--;
       }
    }
    cout << cnt << endl;
    return 0;
}