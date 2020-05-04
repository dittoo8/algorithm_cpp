#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int a,b,c,d;
bool ck[1000][1000];
void bfs(){
    queue<pair<int, int> > q;
    q.push(make_pair(a,b));
    ck[a][b]=true;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        int z= d-x-y;
        if (x == y && y ==z){
            printf("1\n");
            return;
        }
        int nx[]={x,x,y}, ny[] = {y,z,z};
        for(int i=0;i<3;i++){
            int a = nx[i], b=ny[i];
            if (a<b) b-=a, a+=a;
            else if (a>b) a-=b, b+=b;
            else continue;
            int c = d-a-b;
            int x = min(min(a,b),c);
            int y = max(max(a,b),c);
            if (!ck[x][y]){
                q.push(make_pair(x,y));
                ck[x][y]=true;
            }
        }
    }
    printf("0\n");
}
void solve(){
    if (d%3){
        printf("0\n");
        return;
    }else bfs();
}
int main(){
    scanf("%d %d %d", &a, &b, &c);
    d = a+b+c;
    solve();
    return 0;
}