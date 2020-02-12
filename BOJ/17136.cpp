#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int num[6] = {0,5,5,5,5,5};
int map[10][10];
int cnt, res;
void dfs(int y, int x){
    if (x==10){
        dfs(y+1,0);
        return;
    }
    if (y==10){
        res = min(res,cnt);
        return;
    }
    if(map[y][x]==0){
        dfs(y, x+1);
        return;
    }
    for(int len = 5;len >=1;len--){
        if (num[len]==0 || y+len > 10 || x+len > 10) continue;
        bool flag = true;
        for(int j=0;j<len;j++){
            for(int k=0;k<len;k++){
                if(map[y+j][x+k]==0){
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
        }
        if (flag == false) continue;
    for(int j=0;j<len;j++){
        for(int k=0;k<len;k++){
            map[y+j][x+k]=0;
        }
    }
    num[len]--;
    cnt++;
    dfs(y,x+len);
    for(int j=0;j<len;j++){
        for(int k=0;k<len;k++){
            map[y+j][x+k] = 1;
        }
    }
    num[len]++;
    cnt--;
    }
}
int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> map[i][j];
        }
    }
    res = INF;
    dfs(0,0);
    if (res == INF)
    cout << -1 << endl;
    else cout << res << endl;
    return 0;
}