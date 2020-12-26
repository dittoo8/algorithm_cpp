#include <iostream>
#include <string>
using namespace std;
int sum = 0;
int t[] = {
    3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10
    };
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    for (int i=0;i<str.length();i++) {
        sum += t[str[i] - 'A'];
    }
    cout << sum << '\n';
    return 0;
}