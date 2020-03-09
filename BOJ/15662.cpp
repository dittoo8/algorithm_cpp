#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int k,n,res;
vector<vector<int> > a;
vector<int> idx;
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
    if(now>=k-1){
        return;
    }
    if(a[now][(2+idx[now])%8]!=a[now+1][(6+idx[now+1])%8]){
        rotateNext(now+1,dir*=-1);
        idx[now+1]-=dir;
    }
    return;
}
int main(){
    scanf("%d",&k);
    idx.resize(k);
    a.resize(k);
    fill(idx.begin(),idx.end(),8888);
    for(int i=0;i<k;i++){
        for(int j=0;j<8;j++){
            int temp;
            scanf("%1d",&temp);
            a[i].push_back(temp);
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
    for(int i=0;i<k;i++){
        if(a[i][idx[i]%8]==1) res+=1;
    }
    printf("%d\n",res);
    return 0;
}