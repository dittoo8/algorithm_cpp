#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;     
    int arr[10] = {0};
    for(int i=0; i< str.size(); i++){
        arr[str[i] - '0']++;
    }
    int num =0;
    for(int i=0; i< 10; i++){
        if(i!=9 && i!=6) num = max(num, arr[i]);
    }
    cout << max(num, (arr[6] + arr[9] + 1) /2);
    return 0;    
}