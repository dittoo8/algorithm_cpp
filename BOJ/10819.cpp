#include <cstdio>
#include <algorithm>
using namespace std;

int solve(int n) {
    int a[n];
    int ans = 0;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a+n);
    do {
        int sum = 0;
        for (int i=0; i<n-1; i++) {
            sum += abs(a[i]-a[i+1]);
        }
        if (ans < sum) ans = sum;
    } while (next_permutation(a, a+n));
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", solve(n));
    return 0;
}