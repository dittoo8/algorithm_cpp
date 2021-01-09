#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,mx=-1000001,mn = 1000001,x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x > mx) mx = x;
        if(x < mn) mn = x;
    }
    cout << mn << ' ' << mx << '\n';
    return 0;
}