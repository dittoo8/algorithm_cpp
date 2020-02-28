#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int ans = 0, i = 1;
    while (i <= n) {
        ans += (n-i+1);
        i *= 10;
    }
    printf("%d\n", ans);
    return 0;
}