#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    if (next_permutation(a, a+n)) {
        for (int i=0; i<n; i++) printf("%d ", a[i]);
        printf("\n");
    } else printf("-1\n");
    return 0;
}