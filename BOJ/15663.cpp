#include <cstdio>
#include <algorithm>
using namespace std;
int num[8];
int used[8];
int res[8];
int n, m;
void solve(int idx,int before){
    if (idx == m) {
        for (int i = 0; i < m; i++){
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }
    int check[10001] = { 0, };
    for (int i = 0; i < n; i++){
        if (!check[num[i]] && !used[i]){
            used[i] = true;
            check[num[i]] = 1;
            res[idx] = num[i];
            solve(idx + 1, i);
            used[i] = false;
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }
    sort(num, num + n);
    solve(0,-1);
    return 0;
}