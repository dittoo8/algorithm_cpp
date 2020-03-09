#include <cstdio>
#include <cmath>
using namespace std;
int n,idx[4],res;
int a[4][8];
void rotatePrev(int now, int dir){
    if(now<=0){
        return;
    }
    if(a[now][(6+idx[now])%8]!=a[now-1][(2+idx[now-1])%8]){
        rotatePrev(now-1,dir*=-1);
        idx[now-1]-=dir;
    }
    return;
}
void rotateNext(int now, int dir){
    if(now>=3){
        return;
    }
    if(a[now][(2+idx[now])%8]!=a[now+1][(6+idx[now+1])%8]){
        rotateNext(now+1,dir*=-1);
        idx[now+1]-=dir;
    }
    return;
}
int main(){
    for(int i=0;i<4;i++){
        idx[i]=888;
        //톱니가 100번 돌아도 idx가 음수나오지않게 설정
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int rotateIdx, dir;
        scanf("%d %d", &rotateIdx, &dir);
        rotateIdx-=1;
        rotatePrev(rotateIdx,dir);
        rotateNext(rotateIdx,dir);
        idx[rotateIdx]-=dir;
        
    }
    for(int i=0;i<4;i++){
        if(a[i][idx[i]%8]==1) res+= pow(2,i);
    }
    printf("%d\n",res);
    return 0;
}