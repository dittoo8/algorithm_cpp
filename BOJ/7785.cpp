#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> v;
    int n;
    cin >> n;
    v.resize(n);
    string name, op;
    for(int i=0;i<n;i++){
        cin >> name >> op ;
        v[i] = name;
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++){
        if (i+1 < v.size() && v[i] == v[i+1]) i++;
        else cout << v[i] << '\n';
    }
    return 0;
}