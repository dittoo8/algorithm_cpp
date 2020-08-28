#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    int len = (int)str.length();
    vector<string> a;
    a.resize(len);
    for(int i=len-1;i>=0;i--){
        a[i] = str.substr(i,len-i);
    }
    sort(a.begin(),a.end());
    for(int i =0;i<a.size();i++){
        cout << a[i] << '\n';
    }
    return 0;
}