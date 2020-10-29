#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}
vector<pair<int, string> > v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    stable_sort(v.begin(), v.end(),cmp);
    for (int i=0; i<n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}