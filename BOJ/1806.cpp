#include <cstdio>
int n, m, len, sum, left, right;
int a[100000];
int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    int ans = 1e9;
    while (true) {
        if (sum >= m) {
            if (ans > len) ans = len;
            sum -= a[left];
            left++;
            len--;
        } else {
            if (right == n) break;
            sum += a[right];
            right++;
            len++;
        }
    }
    printf("%d\n", ans == 1e9 ? 0 : ans);
    return 0;
}