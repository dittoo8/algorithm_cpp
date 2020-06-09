#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int tmp=0;
        string str;
        cin >> str;
        for(int i=0;i<str.length();i++){
            if (str[i]== '(') tmp++;
            else tmp--;
            if (tmp <0 ) break;
        }
        if (tmp == 0 ) cout << "YES" <<endl; 
        else cout << "NO" <<endl;
    }
    return 0;
}