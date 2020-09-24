#include <iostream>
using namespace std;
long long a, b,ans = -1;
void solve(int len, long long num){
    if(num > b) return;
    if (num == b) {
        if(ans == -1 || ans > len){
            ans = len;
        }
        return;
    }
    solve(len+1,num*2);
    solve(len+1,num*10+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    solve(1,a);
    cout << ans << '\n';
    return 0;
}