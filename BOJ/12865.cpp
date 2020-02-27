#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int, int> > v; //무게, 가치
int d[101][100001];
int n,m;
int dp(int s, int remain){
    if(s==n) return 0;
    if (d[s][remain]!=-1) return d[s][remain];
    d[s][remain]=0;
    d[s][remain] = max(d[s][remain],dp(s+1,remain));
    if(remain >= v[s].first){
        d[s][remain] = max(d[s][remain], dp(s+1,remain-v[s].first)+v[s].second);
    }
    return d[s][remain];
}
int main(){
    memset(d,-1,sizeof(d));
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int tempa,tempb;
        cin >> tempa >> tempb;
        v.push_back(make_pair(tempa,tempb));
    }
    cout << dp(0,m) << endl;
    return 0;
}