#include <iostream>
using namespace std;
int arr[26];
char list[30];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, i, count = 0;
    cin >> n;
    while (n--) {
        cin >> list;
        arr[list[0] - 97]++;
    }
    for (i = 0; i < 26; i++){
        if (arr[i] >= 5) {
            count++;
            cout<< char(i+97);
        }
    }
    if (count==0) {
        cout << "PREDAJA" ;
    }
    return 0;
}
