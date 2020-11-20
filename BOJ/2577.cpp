#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int input, mul=1, result = 0;
    int cnt[10] = { 0, };
    for (int i = 0; i < 3; i++) {
        cin >> input ;
        mul *= input;
    }
    for (int i = 0; mul > 0; i++) {
        result = mul % 10;
        cnt[result] += 1;
        mul /= 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] <<'\n';
    }
    return 0;
}