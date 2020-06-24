#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int s1len = (int)s1.length();
    int s2len = (int)s2.length();
    for(int i=0;i<2500;i++){
        // s1,s2의 길이의 최소공배수가 2500을 넘지않음
        if (s1[i%s1len]!=s2[i%s2len]){
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    return 0;
}