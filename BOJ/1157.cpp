#include <iostream>
#include <string>
using namespace std;
int cnts[27];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i] >= 'A' && str[i] <='Z'){
            cnts[str[i]-'A']++;
        }else {
            cnts[str[i]-'a']++;
        }
    }
    int tmax=0;
    char ans;
    for(int i=0;i<27;i++){
        if(cnts[i]> tmax){
            tmax = cnts[i];
            ans = char(i+'A');
        }else if (cnts[i]==tmax){
            ans = '?';
        }
    }
    cout << ans << '\n';
    return 0;
}