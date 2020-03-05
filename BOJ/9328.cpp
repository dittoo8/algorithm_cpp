#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define MAX 102
using namespace std;
char a[MAX][MAX];
bool ck[MAX][MAX];
bool keys[27];
int h, w;
int dx[] = {-1,0,0,1}, dy[] = {0,1,-1,0};
int bfs(){
    queue<pair<int, int> > q;
    queue<pair<int, int> > dq[26];
    int cnt =0;
    q.push(make_pair(0,0));
    ck[0][0]=true;
    while(!q.empty()){
        int xi = q.front().first, xj = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = xi + dx[i], ny = xj +dy[i];
            if(nx <0 || nx > h+1 || ny <0 || ny >w+1) continue;
            if (a[nx][ny]=='*' || ck[nx][ny]) continue;
            ck[nx][ny] = true;
            if (a[nx][ny]=='$') {
                cnt++;
            } else if (a[nx][ny] >='a' && a[nx][ny] <= 'z'){
                //열쇠
                int k = a[nx][ny]-'a';
                keys[k] = true;
                while(!dq[k].empty()){
                    int kx = dq[k].front().first,ky = dq[k].front().second;
                    dq[k].pop();
                    q.push(make_pair(kx,ky));
                }
            } else if (a[nx][ny] >='A' && a[nx][ny] <= 'Z'){
                //문
                int k = a[nx][ny]+32-'a';
                if (!keys[k]){
                    dq[k].push(make_pair(nx,ny));
                    continue;
                }
            }
            q.push(make_pair(nx,ny));
            ck[nx][ny]= 1;
        }
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(a,'.',sizeof(a));
        memset(ck,false,sizeof(ck));
        memset(keys,false, sizeof(keys));
        cin >> h >> w;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                char c;
                cin >> c;
                if(c!='.') a[i][j]=c;
            }
        }
        string  k;
        cin >> k;
        if(k[0]!='0'){
            for(int i=0;i<k.length();i++){
                keys[k[i]-'a'] = true;
            }
        }
        cout << bfs() << endl;

    }
    return 0;
}