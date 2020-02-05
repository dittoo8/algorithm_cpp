#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define INF 1e9+7
using namespace std;
string str, bomb;
char ans[1000010];
int idx;
bool isMatch(int curPos) {
    for (int i = 0; i<bomb.size(); i++) if (ans[curPos + i] != bomb[i])    return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> str >> bomb;    
    for (int i = 0; i < str.size(); i++) {
        ans[idx++] = str[i];
        if (idx - bomb.size() >= 0 && isMatch(idx - bomb.size()))    idx -= bomb.size();
    }
    if (idx == 0)    cout << "FRULA";
    else for (int i = 0; i < idx; i++)    cout << ans[i];
    return 0;
}
