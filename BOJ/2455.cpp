#include <iostream>
using namespace std;
int main() {
    int ans = 0, sum = 0;
    for (int i=0; i<4; i++) {
        int x, y;
        cin >> x >> y;
        sum += (y-x);
        if (ans < sum) ans = sum;
    }
    cout << ans << '\n';
    return 0;
}