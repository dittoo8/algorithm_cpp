#include <cstdio>
using namespace std;
int sum;
bool visit[1501][1501];
void go(int x,int y){ //DFS 버전
    if(visit[x][y]) return;
    visit[x][y]=true;
    int a[3]={x,y,sum-x-y};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i]<a[j]){
                int b[3]={x,y,sum-x-y};
                b[i]+=a[i];
                b[j]-=a[i];
                go(b[0],b[1]);
            }
        }
    }
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sum= a+b+c;
    if(sum%3!=0){
        printf("0\n");
        return 0;
    }
    go(a,b);
    if(visit[sum/3][sum/3]) printf("1\n");
    else printf("0\n");
    return 0;
}