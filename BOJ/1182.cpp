#include <iostream>
using namespace std;
int n,s, curSum, cnt;
int a[22];
void dfs(int x){
    if (x==n) return;
    if (curSum + a[x] == s) cnt++;
    dfs(x+1);

    curSum+=a[x];
    dfs(x+1);

    curSum-=a[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dfs(0);
    cout << cnt << endl;
    return 0;
}