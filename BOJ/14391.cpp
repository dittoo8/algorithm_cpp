#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int map[4][4];
int dir[4][4];
bool ck[4][4];
vector<int> arr;
int n,m;
vector<int> changeBi(int i){
    vector<int> tmp;
    tmp.resize(n*m);
    for(int j=0;j<n*m;j++){
        tmp[j]=i%2;
        i /=2;
    }
    return tmp;
}
int main(){
    scanf("%d %d", &n ,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    arr.resize(n*m);
    int ans = -1;
    for(int i=0;i<pow(2,(n*m));i++){
        memset(ck,false,sizeof(ck));
        arr = changeBi(i);
        int nl=0;
        int ml=0;
        for(int j=0;j<n*m;j++){
            if (ml==m){
                nl++;
                ml=0;
            }
            dir[nl][ml]= arr[j];
            ml++;
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            int ten = 1;
            for (int j=m-1;j>=0;j--){
                if(dir[i][j]==0 && ck[i][j]==false){
                    ck[i][j]=true;
                    cnt+=map[i][j]*ten;
                    ten *= 10;
                }
                if(dir[i][j]==1) ten = 1;
            }
        }
        for(int j=0;j<m;j++){
            int ten =1;
            for(int i=n-1;i>=0;i--){
                if(dir[i][j]==1 && ck[i][j]==false){
                    ck[i][j]=true;
                    cnt+= map[i][j]*ten;
                    ten *= 10;
                }
                if (dir[i][j]==0) ten = 1;
            }
        }
        if (ans < cnt) ans = cnt;
    }
    printf("%d\n", ans);
    return 0;
}