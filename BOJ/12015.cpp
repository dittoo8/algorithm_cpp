#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> v;
    v.push_back(0);
    int n,x,cnt = 0;
    cin >> n ;
    for(int i=0;i<n;i++){
        cin >> x;
        if ( x > v.back()){
            v.push_back(x);
            cnt++;
        }else {
            int idx = lower_bound(v.begin(), v.end(),x) - v.begin();
            v[idx] = x;
        }
    }
    cout << cnt << '\n';
    return 0;
}