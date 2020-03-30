#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, s, arr[41];
long long cnt;
vector<int> a, b;
void makeA(int idx, int sum){
    sum+=arr[idx];
    if (idx>=n/2) return;
    if(sum==s) cnt++;
    a.push_back(sum);
    makeA(idx+1,sum-arr[idx]);
    makeA(idx+1,sum);
}
void makeB(int idx, int sum){
    sum+=arr[idx];
    if (idx>=n) return;
    if(sum==s) cnt++;
    b.push_back(sum);
    makeB(idx+1,sum-arr[idx]);
    makeB(idx+1,sum);
}
int main(){
    scanf("%d %d", &n, &s);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    makeA(0,0);
    makeB(n/2,0);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<(int)a.size();i++){
        int tmp = s-a[i];
        int l = lower_bound(b.begin(),b.end(),tmp)-b.begin();
        int u = upper_bound(b.begin(),b.end(),tmp)-b.begin();
        cnt+=u-l;
    }

    printf("%lld\n",cnt);
    return 0;
}