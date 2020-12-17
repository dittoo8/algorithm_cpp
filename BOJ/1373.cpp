#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string k;
    string mod ="";
    string ans = "";
    cin >> k;
    int len = k.size();
    int cnt = 0;
    for (int i = len - 1; i >= 0; i--){
        mod += k[i];
        cnt++;
        if (cnt == 3 || i == 0){
            int sum = 0;
            for (int j = 0; j < mod.size(); j++)
                if (mod[j] == '1')
                    sum += pow(2, j);
            mod = "";
            cnt = 0;
            ans += sum + '0';
 
        }
    }
    for (int i = 0; i < ans.size()/2; i++)
        swap(ans[i], ans[ans.size() - 1 - i]);
    cout << ans << '\n';
}