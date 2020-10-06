#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[2];
vector<int> a;
int n,s;
long long answer;
void make_list(int idx, int sum, int ck){
    if(ck == 0 && idx >= n/2) return;
    if(ck == 1 && idx >= n) return;
    if(sum+a[idx] == s) answer++;
    v[ck].push_back(sum+a[idx]);
    make_list(idx+1,sum+a[idx],ck);
    make_list(idx+1,sum,ck);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    make_list(0,0,0);
    make_list(n/2,0,1);
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    for(int i=0;i<v[0].size();i++){
        int tmp = s-v[0][i];
        int l = lower_bound(v[1].begin(),v[1].end(),tmp)-v[1].begin();
        int u = upper_bound(v[1].begin(),v[1].end(),tmp)-v[1].begin();
        answer+=u-l;
    }
    cout << answer << '\n';
    return 0;
}