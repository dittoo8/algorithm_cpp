#include <iostream>
#include <string>
using namespace std;
int idx[27];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc,cnt = 0;
    bool status;
    cin >> tc;
    while(tc--){
        status = true;
        string str;
        cin >> str;
        fill(&idx[0], &idx[26]+1,0);
        for(int i = 0; i < str.length(); i++){
            if(idx[str[i]-'a'] != 0){
                if(str[i-1] != str[i]){
                    status = false;
                    break;
                }
            } 
            idx[str[i]-'a']++;
        }
        if(status) cnt++;
    }
    cout << cnt << '\n';
}