#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,ans=1e9;
vector<pair<int, int> > ch,h;
vector<int> v;
void solve(int idx, int cnt){
    if(idx >(int)ch.size()) return;
    if(cnt == m){
        int sum=0;
        for(int i=0;i<(int)h.size();i++){
            int d= 1e9;
            for(int j=0;j<(int)v.size();j++){
                d = min(d, abs(h[i].first-ch[v[j]].first)+abs(h[i].second-ch[v[j]].second));
            }
            sum+=d;
        }
        ans = min(ans,sum);
        return;
    }
    v.push_back(idx);
    solve(idx+1,cnt+1);
    v.pop_back();
    solve(idx+1,cnt);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            scanf("%d",&a);
            if(a==1) h.push_back(make_pair(i,j));
            else if (a==2) ch.push_back(make_pair(i,j));
        }
    }
    solve(0,0);
    printf("%d\n",ans);
    return 0;
}