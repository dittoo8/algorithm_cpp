#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ans = 0;
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]== 'a' || str[i]== 'e' || str[i]== 'i' || str[i]== 'o' || str[i]== 'u'){
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}