#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int sum = 0;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            string temp = s.substr(start, i - start);
            sum += stoi(temp);
            start = i + 1;
        }
        if (i == s.length() - 1) {
            string temp = s.substr(start, i - start+1);
            sum += stoi(temp);
            }
    }
    cout << sum << endl;
}