#include <iostream>
using namespace std;
int a[11];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int L, P;
    cin >> L >> P;
    int people = L * P;
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        a[i] -= people;
        cout << a[i] << ' ';
    }
    return 0;
}