#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int c[102];
int d[100002];
int main(){
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++){
        scanf("%d", &c[i]);
    }
    
    sort(c+1,c+n+1);
    d[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if (j>=c[i]) {
                d[j] += d[j-c[i]];
            }
        }
    }
    printf("%d", d[k]);
}