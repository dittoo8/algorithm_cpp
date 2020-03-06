#include <cstdio>
using namespace std;
int n, m;
int a[1000];
int ck[1000];
void dfs(int idx){
    if (idx == m)
    {
        for (int i = 0; i < m; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!ck[i]){
            ck[i] = true;
            a[idx] = i;
            dfs(idx + 1);
            ck[i] = 0;
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    dfs(0);
    return 0;
}