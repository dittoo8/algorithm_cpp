#include <cstdio>
#include <queue>
using namespace std;
const int dx[] = {-2,-2,-1,-1,1,1,2,2}, dy[] = {-1,1,-2,2,-2,2,-1,1};
int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        int n;
        queue<pair<int, int> > q;
        scanf("%d", &n);
        int si,sj,ei,ej;
        scanf("%d %d",&si, &sj);
        scanf("%d %d",&ei, &ej);
        int a[301][301]={0,};
        q.push(make_pair(si,sj));
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==ei && y==ej) {
                printf("%d\n",a[x][y]);
                break;
            }
            for(int i=0;i<8;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if (nx<0 || nx >= n || ny <0 || ny>=n) continue;
                if (a[nx][ny]) continue;
                a[nx][ny] = a[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return 0;
}