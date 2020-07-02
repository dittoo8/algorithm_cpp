#include <cstdio>
#include <algorithm>
using namespace std;
int a[51][51];
int n,m,ans=1;
bool check(int x,int y, int len){
    if (x+len >= n || y+len >= m) return false;
    return (a[x][y]== a[x+len][y] && a[x][y]== a[x][y+len] &&a[x][y]== a[x+len][y+len]);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &a[i][j]);
        }
    }
    int l = min(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=1;k<=l;k++){
                if (check(i,j,k)) ans = max(ans,k+1);
            }
        }
    }
    printf("%d\n",ans*ans);
    return 0;
}