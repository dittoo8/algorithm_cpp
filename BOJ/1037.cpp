#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<long long> v;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    cout << v[0]*v[n-1] << '\n';
    return 0;
}