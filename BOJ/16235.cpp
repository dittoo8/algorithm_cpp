#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
const int dx[] = {-1,-1,-1,0,0,+1,+1,+1}, dy[] = {-1,0,+1,-1,+1,-1,0,+1};
struct trees{
    int d;
    //d는 양분
    vector<int> t;
    //심어져 있는 나무
    vector<int> dt;
    //죽은 나무
};
vector<vector<trees> > v;
int n,m,p,a[11][11],res;
void spring(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (v[i][j].t.size()==0) continue;
            if (v[i][j].d==0) v[i][j].t.clear();
            sort(v[i][j].t.begin(),v[i][j].t.end());
            int tS = v[i][j].t.size();
            vector<int> tmpt;
            for(int k=0;k<tS;k++){
                if(v[i][j].d >= v[i][j].t[k]){
                    v[i][j].d -=v[i][j].t[k];
                    tmpt.push_back(v[i][j].t[k]+1);
                } else {
                    //양분을 공급할 수 없다면 현재 칸의 죽은 나무 배열에 추가
                    v[i][j].dt.push_back(v[i][j].t[k]);
                }
            }
            v[i][j].t.clear();
            v[i][j].t = tmpt;
        }
    }
}
void summer(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (v[i][j].dt.size()==0) continue;
            int tS = v[i][j].dt.size();
            for(int k=0;k<tS;k++){
                v[i][j].d+=floor(v[i][j].dt[k]/2);
            }
            v[i][j].dt.clear();
        }
    }
}
void fall(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (v[i][j].t.size()==0) continue;
            int tS = v[i][j].t.size();
            for(int k=0;k<tS;k++){
                if (v[i][j].t[k]%5==0 && v[i][j].t[k]>=5){
                    //5의 배수일때
                    for(int h=0;h<8;h++){
                        int nx = i+dx[h], ny=j+dy[h];
                        if (nx <1 || nx > n || ny <1 || ny >n) continue;
                        v[nx][ny].t.push_back(1);
                    }
                }
            }

        }
    }
}
void winter(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            v[i][j].d+=a[i][j];
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &p);
    vector<trees> tmpv;
    tmpv.resize(n+1);
    v.resize(n+1,tmpv);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            scanf("%d", &tmp);
            v[i][j].d = 5;
            a[i][j] = tmp;
        }
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);
        v[x][y].t.push_back(z);
    }
    for(int i=0;i<p;i++){
        spring();
        summer();
        fall();
        winter();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res+=v[i][j].t.size();
        }
    }
    printf("%d\n",res);
    return 0;
}