#include <iostream>
using namespace std;
int egg[8][2],n;
int attack(int idx){
    if (idx ==n){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(egg[i][0]<=0) cnt++;
        }
        return cnt;
    }
    if(egg[idx][0]<=0){
        return attack(idx+1);
    }
    int ans = 0;
    bool ok = false;
    for(int i=0;i<n;i++){
        if(i == idx) continue;
        if(egg[i][0]>0){
            egg[idx][0]-=egg[i][1];
            egg[i][0]-=egg[idx][1];
            ok = true;
            int tmp = attack(idx+1);
            if(tmp > ans) ans = tmp;
            egg[idx][0]+=egg[i][1];
            egg[i][0]+=egg[idx][1];
        }
    }
    if(!ok) return attack(idx+1);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> egg[i][0] >> egg[i][1];
    }
    cout << attack(0) << '\n';
    return 0;
}