#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        string str;
        cin >> x >> str;
        for(int j=0;j<str.length();j++){
            if(j==x-1) continue;
            cout << str[j];
        }
        cout << '\n';
    }
    return 0;
}