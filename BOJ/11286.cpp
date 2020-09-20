#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
class cmp {
    public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
        return a.second > b.second;
        return a.first > b.first;
    }
};
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top().second << '\n';
            pq.pop();
        } else pq.push(make_pair(abs(x), x));
    }
    return 0;
}
