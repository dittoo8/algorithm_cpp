#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str, target;
    getline(cin, str);
    getline(cin, target);
    if (target.size() > str.size()){
        cout << 0 << '\n';
    }else {
        int cnt = 0;
        for (int i = 0; i < str.size() - target.size() + 1; i++){
            bool findTarget = true;
            for (int j = 0; j < target.size(); j++)
                if (str[i + j] != target[j]){
                    findTarget = false;
                    break;
                }
            if (findTarget){
                cnt++;
                i += target.size() - 1;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}