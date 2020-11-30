#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    string input[5],ans = "";
    for(int i=0;i<5;i++){
        cin >> input[i];
    }
    for(int i=0;i<15;i++){
        for(int j=0;j<5;j++){
            if(input[j].length() < i+1) continue;
            ans+= input[j][i];
        }
    }
    cout << ans << '\n';
    return 0;
}