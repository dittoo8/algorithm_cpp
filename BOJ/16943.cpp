#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int answer = -1;
    string a;
    int b;
    cin >> a >> b;
    sort(a.begin(),a.end());
    do{
        if (a[0]=='0') continue;
        if (stoi(a) <= b) {
            answer = stoi(a);
        }
    }while(next_permutation(a.begin(),a.end()));
    cout << answer << '\n';
    return 0;
}