#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int tc,res_cnt,res_len,n;
int a[13][13];
bool visit[13][13];
const int dx[]={-1,0,0,1}, dy[] = {0,-1,1,0};
vector<pair<int, int> > v;
void backtrack(int idx,int cnt,int len){
    if(idx == (int)v.size()){
        //마지막 core까지 다 체크
        if(cnt > res_cnt){
            res_cnt = cnt;
            res_len = len;
        }else if (cnt == res_cnt && len < res_len){
            res_len = len;
        }
        return;
    }
    int x = v[idx].first,y=v[idx].second;
    int tmp[13][13];
    memcpy(tmp,visit,sizeof(tmp));
    for(int i=0;i<4;i++){
        int nx = x+dx[i],ny=y+dy[i];
        bool lineck =true;
        int tmp_len=0;
        while(true){
            if (nx <0 || nx >=n || ny <0 || ny >=n) break;
            if (a[nx][ny] ||visit[nx][ny]) {
                lineck=false;
                break;
            }
            visit[nx][ny]=true;
            nx+=dx[i];
            ny+=dy[i];
            tmp_len++;
        }
        if(lineck) {
            backtrack(idx+1,cnt+1,len+tmp_len);
        }
        if (tmp_len){
            memcpy(visit,tmp,sizeof(visit));
        }

    }
    backtrack(idx+1,cnt,len);
}
int main(){
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        v.clear();
        memset(a,0,sizeof(a));
        memset(visit,0,sizeof(visit));
        res_cnt=0;
        res_len=0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%1d",&a[i][j]);
                if(a[i][j] && i >0 && i < n && j>0 && j <n){
                    // Core 저장
                    v.push_back(make_pair(i,j));
                }
            }
        }
        backtrack(0,0,0);
        printf("#%d %d\n",t,res_len);
    }
    return 0;
}