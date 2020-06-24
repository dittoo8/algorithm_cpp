#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin >> s >> t;
    while(t.length()> s.length()){
        if (t.back()=='A') t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }
    if (s == t) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}