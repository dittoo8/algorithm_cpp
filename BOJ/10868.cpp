#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 1000000002
using namespace std;
long long num[MAX],tree[4*MAX];
long long make_segTree(int idx, int s, int e){
    int m = (s + e) / 2;
    if(s == e) return tree[idx] = num[s];
    else return tree[idx] = min(make_segTree(2*idx+1,s,m),make_segTree(2*idx+2,m+1,e));
}
int get_min(int idx, int s, int e, int l, int r){
    int m = (s+e)/2;
    if (e < l || r < s) return INF;
    if(l <= s && e <= r) return tree[idx];
    return min(get_min(2*idx+1,s,m,l,r),get_min(2*idx+2,m+1,e,l,r));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    make_segTree(0,0,n-1);
    int a, b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        cout << get_min(0,0,n-1,a-1,b-1) << '\n';
    }
    return 0;
}