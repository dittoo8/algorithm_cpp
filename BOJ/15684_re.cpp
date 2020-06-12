#include <cstdio>
#include <vector>
using namespace std;
int n,m,h,len,ans = -1;
int garo[100][100]; // 가로선 정보 저장
vector<pair<int, int> > a; // 가로선 후보 위치
int start(int c){ // 출발점 c에서 c로 도착할  수 있는지 체크
    int r = 1;
    while(r<=h){
        if (garo[r][c]==1){
            //가로선의 왼쪽인 경우 오른쪽으로 이동
            c++;
        }else if(garo[r][c]==2){
            //가로선의 오른쪽인 경우 왼쪽으로 이동
            c--;
        }
        r++;
    }
    return c;
}
bool go(){ // 전체 사다리 체크
    for(int i=1;i<=n;i++){
        int res = start(i);
        if (res!=i) return false;
    }
    return true;
}
void backtrack(int cnt,int idx){
    if (cnt>3) return; //가로선 3개 이상 만들 수 없음
    for(int i=idx;i<len;i++){
        int x=a[i].first;
        int y=a[i].second;
        if (garo[x][y]!= 0|| garo[x][y+1]!=0) continue;
        garo[x][y]=1;
        garo[x][y+1]=2;
        if (go()){
            if (ans == -1 || ans > cnt) ans = cnt;
        }
        backtrack(cnt+1,i+1);
        garo[x][y]=0;
        garo[x][y+1]=0;
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &h);
    while(m--){
        int u,v;
        scanf("%d %d", &u, &v);
        garo[u][v]= 1; // 가로선의 왼쪽은 1
        garo[u][v+1]= 2; // 가로선의 오른쪽은 2
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=n-1;j++){
            if (garo[i][j]!=0) continue;
            if (garo[i][j+1]!=0) continue;
            // 가로선 만들 수 있는 후보  위치 저장
            a.push_back(make_pair(i,j));
        }
    }
    if (go()){ //가로선 추가없이 사다리 통과
        printf("0\n");
        return 0;
    }
    len = (int)a.size(); //가로선 가능 갯수
    backtrack(1,0);
    printf("%d\n",ans);
    return 0;
}