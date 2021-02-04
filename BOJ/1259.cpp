#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (true) {
        bool flag = false;
        string s;
        cin >> s;
        if (s == "0") break;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                cout << "no\n";
                flag = true;
                break;
            }
        }
        if (!flag) cout << "yes\n";
    }
}