#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1, s2;
    int cnt = 0, cnt2 = 0;
    cin >> s2 >> s1;
    for(int i=0;i<s2.length();i++){
        if(s2[i]=='a') cnt2++;
    }
    for (int i=0;i<s1.length();i++){
        if(s1[i]=='a') cnt++;
    }
    if (cnt <= cnt2){
        cout << "go";
    }else cout << "no";
    return 0;
}
