#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a[27];
    fill(&a[0], &a[26]+1, -1);
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if (a[str[i]-'a'] == -1) {
            a[str[i]-'a'] = i;
        }
    }
    for(int i=0;i<26;i++){
        cout << a[i] << ' ';
    }
    return 0;
}