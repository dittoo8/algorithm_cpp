#include <iostream>
#include <string>
using namespace std;
int num[10];
int main(){
    string a;
    cin >> a;
    int temp = 0;
    for(int i = 0;i<a.size();i++){
        num[a[i]-'0']++;
        temp += a[i] - '0';
    }
    if(temp % 3 == 0 && num[0] != 0){
        for(int i=9;i>=0;i--){
            for(int j=0;j<num[i];j++){
                cout << i;
            }
        }
    } else {
        cout << -1;
    }
    return 0;
}