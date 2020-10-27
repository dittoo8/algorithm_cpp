#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
 
pair<int, int> p[100000];
 
bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second != p2.second) {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}
int main() {
    int n,x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        p[i] = make_pair(x, y);
    }
    sort(p, p + n, compare);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", p[i].first, p[i].second);
    }
    return 0;
}