#include <iostream>
using namespace std;
int main(){
    int tc, m, n;
    cin >> tc;
    while (tc--) {
        long long ans = 1;
        cin >> m >> n;
        for (int i = 1; i <= m; i++){
            ans = ans*(n - i + 1) / i;
        }
        cout << ans << '\n';
    }
    return 0;
}