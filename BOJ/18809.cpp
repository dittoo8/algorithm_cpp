#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,g,r,answer;
struct land {
    int x, y, check;
};
vector<vector<int> > map;
vector<land> v;
queue<pair<int, int> > greenQ;
queue<pair<int, int> > redQ;
const int dx[] = {0,0,-1,1}, dy[]={-1,1,0,0};
void flowers(){
    vector<vector<int> > vt = map;
    while(!redQ.empty()) redQ.pop();
    while(!greenQ.empty()) greenQ.pop();
    for(int i=0;i<v.size();i++){
        if (v[i].check == 2) greenQ.push(make_pair(v[i].x, v[i].y));
        else if (v[i].check == 1) redQ.push(make_pair(v[i].x, v[i].y));
        else vt[v[i].x][v[i].y] = 1;
    }
    int tmpans = 0;
    int x,y;
    int Qs;
    while(!redQ.empty() && !greenQ.empty()){
        Qs = (int)redQ.size();
        for(int k=0;k<Qs;k++){
            x = redQ.front().first;
            y = redQ.front().second;
            redQ.pop();
            if (vt[x][y]== -1) continue;
            vt[x][y] = 2;
            for(int i=0;i<4;i++){
                if (vt[x+dx[i]][y+dy[i]]==1){
                    redQ.push(make_pair(x+dx[i],y+dy[i]));
                    vt[x+dx[i]][y+dy[i]] = 4;
                }
            }
        }
        Qs = (int)greenQ.size();
        for(int k=0;k<Qs;k++){
            x = greenQ.front().first;
            y = greenQ.front().second;
            greenQ.pop();
            for(int i=0;i<4;i++){
                if (vt[x+dx[i]][y+dy[i]]==1){
                    greenQ.push(make_pair(x+dx[i],y+dy[i]));
                    vt[x+dx[i]][y+dy[i]] = 2;
                }else if (vt[x+dx[i]][y+dy[i]]==4){
                    tmpans++;
                    vt[x+dx[i]][y+dy[i]] = -1;
                }
            }
        }
    }
    if (tmpans > answer ){
        answer =tmpans;
    }
}
void backtrackRed(int cnt, int idx){
    if (cnt == r){
        flowers();
        return;
    }
    for(int i=idx;i<v.size();i++){
        if (v[i].check == 0){
            v[i].check = 1;
            backtrackRed(cnt+1,i+1);
            v[i].check = 0;
        }
    }
}
void backtrackGreen(int cnt, int idx){
    if (cnt== g){
        backtrackRed(0,0);
        return;
    }
    for(int i=idx;i<v.size();i++){
        if (v[i].check == 0){
            v[i].check = 2;
            backtrackGreen(cnt+1,i+1);
            v[i].check = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> g >> r;
    map.resize(n+2, vector<int>(m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
            if (map[i][j]==2) {
                v.push_back({i,j,0});
            }
        }
    }
    backtrackGreen(0,0);
    cout << answer << '\n';
    return 0;
}