#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ans =0;
    for(int i=0;i<5;i++){
        int x;
        cin >> x;
        if (x < 40) {
            ans+=40;
        } else {
            ans+=x;
        }
    }
    cout << ans/5 << '\n';
    return 0;
}