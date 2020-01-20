#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[502][502];
int d[502][502];
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d", &a[i][j]);
        }
    }
    d[1][1]= 7;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            d[i][j] = max(d[i-1][j-1],d[i-1][j]) + a[i][j];
        }
    }
    int maxTem = 0;
    for(int i=1;i<=n;i++){
        if(d[n][i]> maxTem) maxTem = d[n][i];
    }
    printf("%d", maxTem);

    return 0;
}