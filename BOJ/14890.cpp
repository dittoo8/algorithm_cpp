#include <iostream>
#include <memory.h>
using namespace std;
int n,l,ans;
int map[101][101];
void slope(int i,bool check){
    int cnt=1;
    for(int j=0;j<n-1;j++){
        int d = check == true ? map[i][j+1]-map[i][j] : map[j+1][i]-map[j][i];
        if (d==0) cnt++;
        else if (d==1 && cnt >=l) cnt = 1;
        else if (d==-1 && cnt >= 0) cnt = -l+1;
        else return;
    }
    if(cnt >=0) ans++;
}
void solve(){
    for(int i=0;i<n;i++){
        slope(i,true);
        slope(i,false);
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}