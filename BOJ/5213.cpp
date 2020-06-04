#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
int n;
int a[500][500][2]; // a[i][j]에 있는 2자리 숫자 {0,1}
bool check[500][500]; // 한 칸 안에서는 자유이동 
pair<int, int> from[500][500]; // 어디서 왔는지 경로 저장
int dist[500][500]; // 해당 정점에 몇번만에 왔는지
//dx0,dy0은 짝수일 때 이동가능한 경로, dx1,dy1은 홀수일 때 이동가능한 경로
int dx0[6]={-1,-1,0,0,1,1};
int dy0[6]={-1,0,-1,1,-1,0};
int dx1[6]={-1,-1,0,0,1,1};
int dy1[6]={0,1,-1,1,0,1};
bool ok(int x, int y){ //(x,y) 타일이 존재하는지
    if(x<0 || x>=n) return false;
    if(x%2==0){
        // 짝수면 n개의 요소
        return y>= 0 && y < n;
    }else return y>=0 && y < n-1; //홀수면 n-1개의 요소
}
bool go(int x1, int y1, int x2, int y2){ //(x1,y1)에서 (x2,y2)로 갈 수 있는지
    if(x1==x2){
        //y1이 왼쪽 요소이면 현재 요소의 오른쪽과 다음 요소의 왼쪽이 같아야 이동가능
        if(y1<y2) return a[x1][y1][1]==a[x2][y2][0];
        else return a[x1][y1][0]==a[x2][y2][1];
    }else {
        if(x1%2==0){
            if(y1==y2) return a[x1][y1][1]==a[x2][y1][0];
            else return a[x1][y1][0]==a[x2][y2][1];
        }else {
            if(y1==y2) return a[x1][y1][0]==a[x2][y2][1];
            else return a[x1][y1][1]==a[x2][y2][0];
        }
    }
}
int num(int x, int y){
    int ans = x/2*(n*2-1);
    if(x%2==1) ans+=n;
    ans+= y+1;
    return ans;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            scanf("%d %d",&a[i][j][0], &a[i][j][1]);
        }
        if(i%2==0){
            scanf("%d %d", &a[i][n-1][0], &a[i][n-1][1]);
        }
    }
    queue<pair<int, int > > q;
    check[0][0]=true;
    dist[0][0]=1;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int k=0;k<6;k++){
            int nx,ny;
            if(x%2==0){
                nx = x+dx0[k];
                ny = y+dy0[k];
            }else {
                nx = x+dx1[k];
                ny = y+dy1[k];
            }
            if(!ok(nx,ny)) continue;
            if(!go(x,y,nx,ny)) continue;
            if(check[nx][ny]) continue;
            check[nx][ny]=true;
            dist[nx][ny]=dist[x][y]+1;
            from[nx][ny]=make_pair(x,y);
            q.push(make_pair(nx,ny));
        }
    }
    int x = n-1;
    int y=n-1;
    while(!check[x][y]){
        y--;
        if(y<0){
            x--;
            y=n-1;
            if(x%2==1) y--;
        }
    }
    printf("%d\n",dist[x][y]);
    stack<pair<int, int> > s;
    while(!(x==0 && y==0)){ // 경로 추적
        s.push(make_pair(x,y));
        auto p = from[x][y];
        x=p.first;
        y=p.second;
    }
    s.push(make_pair(x,y));
    while(!s.empty()){
        printf("%d ",num(s.top().first,s.top().second));
        s.pop();
    }
    printf("\n");
    return 0;
}