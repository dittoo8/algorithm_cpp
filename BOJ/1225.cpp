#include <iostream>
#include <cstring>
#define MAX 10001
char a[MAX], b[MAX];
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    long long x=0, y=0;
    auto al = strlen(a);
    for (int i=0; i<al; i++) {
        x += a[i] - '0';
    }
    auto bl = strlen(b);
    for (int i=0; i<bl; i++) {
        y += b[i] - '0';
    }
    cout << x*y << '\n';
    return 0;
}