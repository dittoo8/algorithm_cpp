#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int d[1001][3];
int a[1001][3];
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&a[i][0], &a[i][1], &a[i][2]);
    }
    int maxres = 1000*n+1;
    int ans = 1e6+1;
    for(int k=0;k<3;k++){
        for(int i=0;i<3;i++){
            if(i==k) d[0][i]=a[0][i];
            else d[0][i] = maxres;
        }
        for(int i=1;i<n;i++){
            d[i][0] = min(d[i-1][1],d[i-1][2])+a[i][0];
            d[i][1] = min(d[i-1][0],d[i-1][2])+a[i][1];
            d[i][2] = min(d[i-1][0],d[i-1][1])+a[i][2];
        }
        for(int i=0;i<3;i++){
            if (i==k) continue;
            ans = min(ans,d[n-1][i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}