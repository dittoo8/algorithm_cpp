#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long answer=0;
    int t;
    cin >> t;
    int n,m;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    vector<int> x;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            x.push_back(sum);
        }
    }
    vector<int> y;
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=i;j<m;j++){
            sum+=b[j];
            y.push_back(sum);
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int i=0;i<x.size();i++){
        auto p = equal_range(y.begin(),y.end(),t-x[i]);
        answer+= p.second - p.first;
    }
    cout << answer << '\n';
    return 0;
}