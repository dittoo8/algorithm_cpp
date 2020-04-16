#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int tc;
    scanf("%d",&tc);
    int si,sj,ei,ej;
    for(int t=1;t<=tc;t++){
        scanf("%d %d %d %d", &si, &sj, &ei, &ej);
        pair<int, int> dist;
        dist = {abs(si-ei),abs(sj-ej)};
        if (abs(dist.first-dist.second)%2==0){
            printf("#%d %d\n",t,max(dist.first,dist.second)*2);
        }else {
            printf("#%d %d\n",t,max(dist.first,dist.second)*2-1);
        }
        
    }
    return 0;
}