#include <iostream>
#include <vector>
#define MAX 8
using namespace std;
const int dx[]= {0,1,0,-1}, dy[] = {1,0,-1,0};
struct pos {
    int x,y,num;
};
int n,m;
vector<vector<int> > a;
vector<pos> cctv;
vector<int> dirs;
void check(vector<vector<int> > &b, int x, int y , int dir){
    int i=x,j=y;
    while(0<=i && i <n && 0<=j && j < m){
        if (b[i][j]==6) break;
        b[i][j]=7;
        i+=dx[dir];
        j+=dy[dir];
    }
}
int solve(int idx){
    if (idx == cctv.size()){
        vector<vector<int> > b(a);
        for(int i=0;i<cctv.size();i++){
            int d,x,y;
            x = cctv[i].x;
            y = cctv[i].y;
            d = cctv[i].num;
            if(d ==1){
                check(b,x,y,dirs[i]);
            }else if (d==2){
                check(b,x,y,dirs[i]);
                check(b,x,y,(dirs[i]+2)%4);
            }else if (d ==3){
                check(b,x,y,dirs[i]);
                check(b,x,y,(dirs[i]+1)%4);
            }else if (d==4){
                check(b,x,y,dirs[i]);
                check(b,x,y,(dirs[i]+1)%4);
                check(b,x,y,(dirs[i]+2)%4);
            }else if (d==5){
                check(b,x,y,dirs[i]);
                check(b,x,y,(dirs[i]+1)%4);
                check(b,x,y,(dirs[i]+2)%4);
                check(b,x,y,(dirs[i]+3)%4);
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
    int answer = 100;
    for(int i=0;i<4;i++){
        dirs[idx] = i;
        int temp = solve(idx+1);
        if(answer>temp) answer = temp;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if (a[i][j]>=1 && a[i][j]<=5){
                cctv.push_back({i,j,a[i][j]});
                dirs.push_back(0);
            }
        }
    }
    cout << solve(0) <<'\n';
    return 0;
}