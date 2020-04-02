#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int as,bs,a[1001],b[1001];
long long res,t;
vector<int> va, vb;
int main(){
    scanf("%lld", &t);
    scanf("%d",&as);
    for(int i=0;i<as;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d", &bs);
    for(int i=0;i<bs;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<as;i++){
        long long tmp=0;
        for(int j=i;j<as;j++){
            tmp+=a[j];
            va.push_back(tmp);
        }
    }
    for(int i=0;i<bs;i++){
        long long tmp=0;
        for(int j=i;j<bs;j++){
            tmp+=b[j];
            vb.push_back(tmp);
        }
    }
    sort(vb.begin(),vb.end());
    for(int i=0;i<va.size();i++){
        long long tmp = t-va[i];
        int l = lower_bound(vb.begin(),vb.end(),tmp)-vb.begin();
        int u = upper_bound(vb.begin(),vb.end(),tmp)-vb.begin();
        res += (u-l);
    }
    printf("%lld\n",res);

    return 0;
}