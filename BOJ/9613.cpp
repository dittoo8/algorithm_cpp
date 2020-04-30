#include <cstdio>

int gcd(int x, int y) {
    while (y != 0) {
        int r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    int t, n, a[100];
    scanf("%d", &t);
    while (t--) {
        long long sum = 0;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                sum += gcd(a[i], a[j]);
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}