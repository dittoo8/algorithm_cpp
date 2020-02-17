#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(string a, string b){
    if (a.length() == b.length()) return a < b;
    else if (a.length() < b.length())return 1;
    return 0;
}
int main(){
    int n;
    vector<string> v;
    cin >> n;
    for(int i=0;i<n;i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if (v[i+1]!=v[i]){
            cout << v[i] << endl;
        }
    }
    return 0;
}