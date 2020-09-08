#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<string> v1;
    vector<string> v2;
    vector<string> res;
    int n,m;
    cin >> n >> m;
    v1.resize(n);
    v2.resize(m);
    for(int i=0;i<n;i++){
        cin >> v1[i];
    }
    for(int i=0;i<m;i++){
        cin >> v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if (v1[i]==v2[j]){
            res.push_back(v1[i]);
            i++;j++;
        }else if (v1[i]>v2[j]){
            j++;
        }else i++;
    }
    cout << res.size() << '\n';
    for(int i=0;i<res.size();i++){
        cout << res[i] << '\n';
    }
    return 0;
}