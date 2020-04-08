#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<pair<int, int> > v;
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        v.clear();
        int n,res;
        scanf("%d", &n);
        v.resize(n,{0,0});
        for(int i=0;i<n;i++){
            scanf("%d %d", &v[i].second, &v[i].first);
            //Ti, Di입력
        }
        sort(v.begin(),v.end());
        res = v.back().first-v.back().second;
        v.pop_back();
        while(!v.empty()){
            int ed = v.back().first;
            int st = ed-v.back().second;
            v.pop_back();
            if(res <=ed){
                res = st- (ed-res);
            }else res = st;
        }
        printf("#%d %d\n",t,res);
        
    }
    return 0;
}