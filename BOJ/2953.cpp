#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x,idx,sum=0,ans=0;
    for(int i=1;i<=5;i++){
        for(int j=0;j<4;j++){
            cin >> x;
            sum+=x;
        }
        if(sum > ans){
            ans = sum;
            idx = i;
        }
        sum = 0;
    }
    cout << idx << ' ' << ans << '\n';
    return 0;
}