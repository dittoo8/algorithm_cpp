#include <iostream>
#include <math.h>
#include <string>
using namespace std;
string str[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
string input[3];
int arrint[3];
long long int ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> input[0] >> input[1] >> input[2];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (input[i] == str[j]) {
                arrint[i] = j;
                break;
            }
        }
    }
    ans = (arrint[0] * 10) + arrint[1];
    ans *= pow(10, arrint[2]);
    cout << ans << endl;
    return 0;
}