#include <cstdio>
#include <queue>
#define MAX 100001
using namespace std;
char a[2][MAX];
bool visit[2][MAX];
int n,k;
void bfs(){
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    visit[0][0]=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<(int)q.size();j++){
            int x = q.front().first, y = q.front().second;
            q.pop();
            int nx[] = {x,x,!x},ny[] = {y-1,y+1,y+k};
            for(int m=0;m<3;m++){
                if(ny[m]>=n) {
                    printf("1\n");
                    return;
                }
                if(ny[m]<=i || visit[nx[m]][ny[m]] || a[nx[m]][ny[m]]=='0') continue;
                q.push(make_pair(nx[m],ny[m]));
                visit[nx[m]][ny[m]]= true;
            }
        }
    }
    printf("0\n");
    return;
}
int main(){
    scanf("%d %d", &n, &k);
    scanf("%s %s", a[0], a[1]);
    bfs();
    return 0;
}