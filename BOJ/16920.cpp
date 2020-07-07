#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n,m,p;
const int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
queue<pair<int, int> > q[10];
long long s[10];
int a[1001][1001];
int  cnt;
int ans[10];
void bfs(int now){
    for(int i=0;i<s[now];i++){
        int qS = q[now].size();
        if (qS == 0) return;
        while(qS--){
            int x = q[now].front().first;
            int y = q[now].front().second;
            q[now].pop();
            for(int k=0;k<4;k++){
                int nx = x+dx[k], ny = y+dy[k];
                if (nx<0||nx >= n ||ny <0 || ny>=m) continue;
                if (a[nx][ny]!=0) continue;
                a[nx][ny]=now;
                ans[now]++;
                q[now].push(make_pair(nx,ny));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> p;
    for(int i=1;i<=p;i++){
        cin>> s[i];
    }
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<m;j++){
            if(isdigit(str[j])){
                int tmp = str[j]-'0';
                a[i][j]=tmp;
                q[a[i][j]].push(make_pair(i,j));
                ans[a[i][j]]++;
            }else if (str[j]=='#') {
                a[i][j]=-1;
            }
        }
    }
    while(true){
        int ck = 0;
        for(int i=1;i<=p;i++){
            if(q[i].empty()) {
                ck++;
            } else bfs(i);
        }
        if(ck == p) break;
    }

    for(int i=1;i<=p;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}