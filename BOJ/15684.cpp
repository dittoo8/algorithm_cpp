#include <cstdio>
using namespace std;
int n,m,h,ans=4;
bool a[31][11];
bool ladder(){
    for(int i=1;i<=n;i++){
        int k = i;
        for(int j=1;j<=h;j++){
            if(a[j][k])k++;
            else if (k>0 && a[j][k-1]) k--;
        }
        if(i!=k) return false;
    }
    return true;
}
void solve(int r, int cnt , int ladderCnt){
    if (ans <= cnt) return;
    if(cnt >=ladderCnt){
        if(ladder()) ans = cnt;
        return;
    }
    for(int i=r;i<=h;i++){
        for(int j=1;j<n;j++){
            if(a[i][j] || a[i][j-1] ||a[i][j+1]) continue;
            a[i][j]=true;
            solve(i,cnt+1,ladderCnt);
            a[i][j]=false;
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &h);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u, &v);
        a[u][v]=true;
    }
    for(int i=0;i<4;i++){
        solve(1,0,i);
        if(ans!=4) break;
    }
    ans == 4 ? printf("-1\n") : printf("%d\n",ans);
    return 0;
}