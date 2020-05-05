#include <cstdio>
#include <queue>
using namespace std;
int main(){
    const int dx[] = {-1,0,0,1}, dy[] = {0,-1,1,0};
    int a[16][16];
    for(int t=1;t<=10;t++){
        int n;
        scanf("%d", &n);
        bool ck[16][16] = {false,};
        int res = 0;
        queue<pair<int, int> > q;
        int si,sj,ei,ej;
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                scanf("%1d", &a[i][j]);
                if (a[i][j]==2) {
                    si = i;
                    sj = j;
                }else if (a[i][j]==3){
                    ei=i;
                    ej=j;
                }
            }
        }
        q.push(make_pair(si,sj));
        ck[si][sj]=true;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            if (x==ei && y==ej) {
                res=1;
                break;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i], ny = y+dy[i];
                if (nx <0 || nx >=16 || ny < 0 || ny >=16) continue;
                if (a[nx][ny]!=1 && !ck[nx][ny]) {
                    ck[nx][ny]=true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        printf("#%d %d\n",t,res);
    }
    return 0;
}