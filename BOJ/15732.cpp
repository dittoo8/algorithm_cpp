#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 1000000
using namespace std;
struct dotori{
    int s,e,d;
    //s: 규칙시작, e:규칙 끝, d : 거리
};
vector<dotori> v;
int n,m,k;
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<m;i++){
        int q,w,e;
        scanf("%d %d %d", &q, &w, &e);
        v.push_back({q,w,e});
    }
    int l=0,r=MAX;
    while(l<r){
        int mid = (l+r)/2;
        int t=0;
        for(int i=0;i<v.size();i++){
            if(t>k) break;
            else if (v[i].s > mid) continue;
            if(v[i].e<mid) t+=(v[i].e-v[i].s)/v[i].d+1;
            else t+=(mid-v[i].s)/v[i].d+1;
        }
        if(t>=k) r=mid;
        else l =mid+1;
    }
    printf("%d\n", l);
    return 0;
}