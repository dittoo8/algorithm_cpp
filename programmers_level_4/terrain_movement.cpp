#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[] = {0,0,-1,1} , dy[] = {-1,1,0,0};
int idx[301][301];
vector<vector<int> > land2;
int parent[90001];
int h,n,cnt;
struct nodes {
    // 비용, 노드1, 노드2
    int cost,no1,no2;
};
vector<nodes> v;
bool cmp(nodes v1, nodes v2){
    return v1.cost < v2.cost;
}
int getP(int x){
    if (parent[x]==x) return x;
    else return getP(parent[x]);
}
void unionP(int x, int y){
    x = getP(x);
    y = getP(y);
    // 값이 더 작은 값으로 부모 합치기
    if (y < x){
        parent[x] = y;
    }else parent[y]=x;
}
void dfs(int x, int y){
    idx[x][y]=cnt;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny = y+dy[i];
        if (nx <0 || nx >= n || ny <0 || ny >=n) continue;
        if (abs(land2[nx][ny]-land2[x][y])<=h && idx[nx][ny]==0){
            dfs(nx,ny);
        }
    }
}
int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    h = height;
    n = land[0].size();
    land2 = land;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (idx[i][j]==0) {
                //각 칸에 인덱스 부여해주기
                cnt++;
                dfs(i,j);
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        // 초기 부모 값은 자기 자신
        parent[i] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                int nx = i+ dx[k], ny = j+dy[k];
                if (nx <0 || nx >=n || ny <0 || ny >= n)continue;
                if (idx[i][j]!=idx[nx][ny]){
                    //인접 칸의 인덱스가 다르다면, nodes 벡터에 추가
                    v.push_back({abs(land[nx][ny]-land[i][j]),idx[i][j],idx[nx][ny]});
                }
            }
        }
    }
    int unionCnt = 0;
    // 비용이 적은 순으로 정렬
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if (getP(v[i].no1)!=getP(v[i].no2)){
            // 현재 인접한 칸의 두 인덱스 간의 부모값이 다르다면 union 실행
            unionP(v[i].no1,v[i].no2);
            answer+=v[i].cost;
            unionCnt++;
            // 사이클이 생기지 않으므로 전체 인덱스-1개의 union을 실행했다면 종료 
            if(unionCnt == cnt-1) break;
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > vec = {
        {1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}
    };
    cout << solution(vec,3) << endl;
    return 0;
}