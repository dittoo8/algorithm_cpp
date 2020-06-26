#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin, s);
    vector<string> a;
    string now = "";
    for(int i=0;i<s.size();i++){
        if (s[i]==' ' || s[i]==',' || s[i]==';'){
            if (now.length() > 0) {
                a.push_back(now);
            }
            now = "";
        }
       else now+=s[i];
    }

    string base = a[0];

    for (int i=1; i<a.size(); i++) {
        string t = base;
        string s = a[i];
        while (s.length() > 0 && !('a' <= s.back() && s.back() <= 'z')) {
            if (s.back() == '[') {
                t += ']';
            } else if (s.back() == ']') {
                t += '[';
            } else {
                t += s.back();
            }
            s.pop_back();
        }
        cout << t << ' ' << s << ';' << '\n';
    }
}