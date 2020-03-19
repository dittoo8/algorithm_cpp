#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long minr=1000000002,maxr=-1000000002;
int op[4];
long long num[13];
void backtrack(int idx, long long tsum){
    if(idx == n){
        minr = min(minr,tsum);
        maxr = max(maxr,tsum);
        return;
    }
    for(int i=0;i<4;i++){
        if(op[i]){
            op[i]--;
            long long tmp=tsum;
            if(i==0) tmp+=num[idx];
            else if (i==1) tmp-=num[idx];
            else if (i==2) tmp*=num[idx];
            else tmp/=num[idx];
            backtrack(idx+1,tmp);
            op[i]++;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&num[i]);
    }
    for(int i=0;i<4;i++){
        scanf("%d",&op[i]);
    }
    backtrack(1,num[0]);
    printf("%lld\n",maxr);
    printf("%lld\n",minr);
    return 0;
}