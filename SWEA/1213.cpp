#include <iostream>
#include <string>

using namespace std;
int main(){
    int n,ans;
    for(int tc=1;tc<=10;tc++){
        ans = 0;
        string target, str;
        cin >> n >> target >> str;
        int targetLength = target.length();
        for(int i=0;i<str.length()-target.length()+1;i++){
            if (str[i] == target[0]){
                if (str.substr(i,targetLength) == target) {
                    ans++;
                }
            }
        }
        cout << '#' << tc <<' ' << ans << '\n';
    }
    return 0;
}