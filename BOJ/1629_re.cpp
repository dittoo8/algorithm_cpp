#include <iostream>
using namespace std;
long long a, b, c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    long long ans = 1;
    while(b>0){
        if (b%2 == 1){
            ans*=a;
            ans%=c;
        }
        a*=a;
        a%=c;
        b/=2;
    }
    cout << ans << '\n';
    return 0;
}