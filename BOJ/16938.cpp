#include <iostream>
#include <algorithm>
using namespace std;
long long a[16];
int n;
long long l, r, x;
int solve(int idx, int cnt, long long sum,long long mn, long long mx){
    if (idx == n){
        if (cnt >=2 && l <= sum && sum <= r && mx-mn >= x) return  1;
        else return 0;
    }
    int cnt1 = solve(idx+1, cnt+1, sum+a[idx],min(mn,a[idx]),max(mx,a[idx]));
    int cnt2 = solve(idx+1, cnt, sum, mn, mx);
    return cnt1+cnt2;
}
int main(){
    cin >> n >> l >> r >> x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << solve(0,0,0,10000000,0) << '\n';
    return 0;
}