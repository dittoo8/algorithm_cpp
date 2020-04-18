#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int n;
char a[10][10];
vector<int> v;
bool possible(int idx) {
    int sum = 0;
    for (int i=idx; i>=0; i--) {
        sum += v[i];
        if (a[i][idx] == '+' && sum <= 0) return false;
        if (a[i][idx] == '0' && sum != 0) return false;
        if (a[i][idx] == '-' && sum >= 0) return false;
    }
    return true;
}
void solve(int idx) {
    if (idx == n) {
        for (auto k : v) printf("%d ", k);
        printf("\n");
        exit(0);
    }
    for (int i=-10; i<11; i++) {
        v.push_back(i);
        if (possible(idx)) solve(idx+1);
        v.pop_back();
    }
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            scanf(" %1c", &a[i][j]);
        }
    }
    solve(0);
    return 0;
}