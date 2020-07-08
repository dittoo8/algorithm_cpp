#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    string str;
    int tc;
    vector<int> alpha[26];
    cin >> str >> tc;
    for(int i=0;i<str.size();i++){
        alpha[str[i]-'a'].push_back(i);
    }
    while(tc--){
        char c;
        int l,r;
        cin >> c >> l >> r;
        cout << upper_bound(alpha[c-'a'].begin(),alpha[c-'a'].end(),r) - lower_bound(alpha[c-'a'].begin(),alpha[c-'a'].end(),l) << '\n';
    }
    return 0;
}