#include <cstdio>
using namespace std;
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int main(){
    int tc,n;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        scanf("%d", &n);
        int a[11][11]={0,};
        int x=0,y=0;
        int num=1;
        int maxnum = n*n;
        int tmpn=n;
        int i=0;
        while(true){
            a[x][y] = num;
            num++;
            if (num > maxnum) break;
            if (x+dx[i]<0 || x+dx[i]>=n || y+dy[i]<0|| y+dy[i]>=n || a[x+dx[i]][y+dy[i]]>0){
                i++;
                if (i>3) i=0;
                tmpn--;
            }
            x+=dx[i];
            y+=dy[i];
        }
        printf("#%d\n",t);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}