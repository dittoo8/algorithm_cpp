#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, mx = 0, idx;
    for(int i=1;i<=9;i++){
        cin >> x;
        if(x > mx ){
            mx = x;
            idx = i;
        }
    }
    cout << mx << '\n';
    cout << idx << '\n';
    return 0;
}