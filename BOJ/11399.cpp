#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<pair<int, int> > p;
    int sum[1002];
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        p.push_back(make_pair(a, i));
    }
    sort(p.begin(), p.end());
    int res = 0;
    for(int i=0;i<p.size();i++){
        sum[i] = sum[i-1] + p[i].first;
    }
    for(int i=0;i<n;i++){
        res += sum[i];
    }
    cout << res << endl;
    return 0;
}