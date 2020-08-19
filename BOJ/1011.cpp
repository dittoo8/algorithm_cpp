#include <cstdio>
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y, ans = 1;
        unsigned int gap, pos = 1;
        scanf("%d %d", &x, &y);
        gap = y - x; // 두 지점 사이의 거리 
        for (int i = 2; pos < gap; i++) {
            pos += i / 2; // pos는 현재 위치이며 gap보다 작아야 한다.
            ans++;
        }
        if (pos > gap) ans--;
        printf("%d\n", ans);
    }
    return 0;
}