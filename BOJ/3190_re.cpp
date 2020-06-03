#include <cstdio>
#include <cstring>
using namespace std;
int d[100][100];
bool apple[100][100];
int op[10001];
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int main(){
    int n,k,x=0,y=0,l;
    scanf("%d", &n);
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        u--,v--;
        apple[u][v]=true;
    }
    memset(d,-1,sizeof(d));
    d[x][y]=0;
    scanf("%d", &l);
    for(int i=0;i<l;i++){
        int u;
        char c;
        scanf("%d %c", &u, &c);
        if(c=='D') op[u]=1;
        else op[u]=-1;
    }
    int dir=0;
    int t=1;
    int len =1;
    while(true){
        x+=dx[dir];
        y+=dy[dir];
        if (x <0 || x >=n || y<0 || y>=n){
            // 범위 벗어나면 끝
            break;
        }else {
            if(apple[x][y]){
                apple[x][y]=false;
                len++;
            }
            if (d[x][y]!=-1 && t-d[x][y]<=len){
                break;
            }
            d[x][y]=t;
        }
        if (op[t]==1){
            dir+=1;
            if(dir>3) dir=0;
        }else if(op[t]==-1){
            dir-=1;
            if(dir<0) dir=3;
        }
        t++;
    }
    printf("%d\n",t);
    return 0;
}