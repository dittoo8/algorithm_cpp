#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;
int a[17][17],n;
int d[17][1<<16];
int TSP(int cur, int vis){
    int &ret = d[cur][vis];
    if(ret != -1) return ret;
    if(vis == (1<<n)-1){
        if (a[cur][0]!=0) return a[cur][0];
        return IMPOSSIBLE;
    }
    ret = IMPOSSIBLE;
    for(int i=0;i<n;i++){
        if(vis & (1<<i) || a[cur][i]==0) continue;
        ret = min(ret,TSP(i,vis|(1<<i)) + a[cur][i]);
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
    memset(d,-1,sizeof(d));
   printf("%d\n",TSP(0,1));
    return 0;
}