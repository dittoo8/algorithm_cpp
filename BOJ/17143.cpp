#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R,C,M;
const int dx[] = {0,-1,1,0,0},dy[]={0,0,0,1,-1};
int map[102][102];
struct shark {
    int r,c,s,d,z;
    bool isAlive;
};
vector<shark> vt;
int getShark(int c){
    int size = 0;
    for(int i=1;i<=R;i++){
        if (map[i][c]!=0){
            size = vt[map[i][c]].z;
            vt[map[i][c]].isAlive = false;
            map[i][c] = 0;
            break;
        }
    }
    return size;
}
void sharkMove(){
    for(int i=1;i<=M;i++){
        if(!vt[i].isAlive) continue;
        auto now = vt[i];
        if (map[now.r][now.c]==i){
            map[now.r][now.c] = 0;
        }
        if (now.d<=2) now.s%=((R-1)*2);
        else now.s%= ((C-1)*2);
        for(int j=0;j<now.s;j++){
            now.r += dx[now.d];
            now.c += dy[now.d];
            if (now.r <1 || now.c < 1 || now.r > R || now.c > C){
                if (now.d == 1 || now.d == 3) now.d++;
                else now.d--;
                now.r += dx[now.d];
                now.c += dy[now.d];
                j--;
            }
        }
        vt[i].r = now.r;
        vt[i].c = now.c;
        vt[i].d = now.d;
        if (map[now.r][now.c] ==0){
            map[now.r][now.c] = i;
        }else  if  (map[now.r][now.c] < i){
            int  tmp = vt[map[now.r][now.c]].z;
            if (now.z > tmp){
                vt[map[now.r][now.c]].isAlive = false;
                map[now.r][now.c] = i;
            }else {
                vt[i].isAlive = false;
            }
        }else map[now.r][now.c] = i;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> M;
    if (M ==0) {
        cout << 0 << '\n';
        return 0;
    }
    int r,c,s,d,z;
    vt.resize(M+1);
    for(int i=1;i<=M;i++){
        cin >> r >> c >> s >> d >> z ;
        vt[i]= {r,c,s,d,z,true};
        map[r][c] = i;
    }
    int ans = 0;
    for(int i=1;i<=C;i++){
        ans+=getShark(i);
        sharkMove();
    }
    cout << ans << '\n';
    return 0;
}