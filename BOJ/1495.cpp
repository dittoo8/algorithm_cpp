#include  <iostream>
#include <cstring>
using namespace std;
int n,s,m;
int v[101];
int d[101][1001];
int dp(int idx, int vol){
    if (vol <0 || vol > m) return -100;
    if(idx == n ) return vol;
    if (d[idx][vol]!=-1) return d[idx][vol];
    return d[idx][vol] = max(dp(idx+1,vol+v[idx+1]),dp(idx+1,vol-v[idx+1]));
}
int main(){
    memset(d,-1,sizeof(d));
    cin >> n >> s >> m;
    for(int  i=1;i<=n;i++){
        int temp;
        cin >> temp;
        v[i]=  temp;
    }
    int res = dp(0,s);
    if(res == -100) cout << -1 <<endl;
    else  cout  << res << endl;
    return 0;
}