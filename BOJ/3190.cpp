#include <cstdio>
#include <deque>
using namespace std;
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int n,a[101][101],k,m;
int rotateIdx[10001];
int solve(){
    int dir = 0;
    deque<pair<int, int > > dq;
    dq.push_back(make_pair(1,1));
    a[1][1]=2;
    int time=0;
    while(1){
        int headi =dq.front().first, headj=dq.front().second;
        if(headi <= 0 || headi >n || headj <=0 || headj >n){
            return time;
        }
        if (rotateIdx[time]>0){
            dir++;
            if(dir==4) dir=0;
        }else if(rotateIdx[time]<0){
            dir--;
            if(dir==-1) dir=3;
        }
        if (a[headi+dx[dir]][headj+dy[dir]]==2) {
            //자신과 충돌,
            return time+1;
        }
        if(a[headi+dx[dir]][headj+dy[dir]]==0){
            //사과가 없을때,
            a[dq.back().first][dq.back().second]=0;
            dq.pop_back();
        }else if (a[headi+dx[dir]][headj+dy[dir]]){
            a[headi+dx[dir]][headj+dy[dir]]=0;
        }
        dq.push_front(make_pair(headi+dx[dir],headj+dy[dir]));
        a[headi+dx[dir]][headj+dy[dir]]=2;
        time++;
    }
    return 0;
}
int main(){
    scanf("%d %d",&n, &k);
    for(int i=0;i<k;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        a[u][v]=1;
    }
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        int z;
        char y;
        scanf("%d %c",&z, &y);
        if(y=='D'){
            rotateIdx[z]=1;
        }else if(y=='L'){
            rotateIdx[z]=-1;
        }
    }
    printf("%d\n",solve());
    return 0;
}