#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a, k;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    cout << v[a-1] << '\n';
    return 0;
}
