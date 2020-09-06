#include <iostream>
#include <string>
using namespace std;
string str;
int cl = 0, sl = 0, num = 0, sp = 0;//cl:대문자, sl:소문자, num:숫자, sp: 공백
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (getline(cin, str, '\n')) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= 65 && str[i] <= 90)
                ++cl;
            else if (str[i] >= 97 && str[i] <= 122)
                ++sl;
            else if (str[i] == ' ')
                ++sp;
            else
                ++num;
        }
        cout << sl << " " << cl << " " << num << " " << sp << endl;
        cl = 0, sl = 0, num = 0, sp = 0;
    }
}
