#include <cstdio>
using namespace std;
int main(){
    int d[1025][1025] = {0};
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp;
            scanf("%d", &temp);
            d[i][j] = d[i][j-1]+d[i-1][j]-d[i-1][j-1] + temp;
        }
    }
    while(m--){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        printf("%d\n", d[x2][y2]-d[x2][y1-1]-d[x1-1][y2]+d[x1-1][y1-1]);
    }
    return 0;
}