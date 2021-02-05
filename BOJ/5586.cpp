#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    int j_c = 0, i_c = 0;
    cin >> str;
    for (int i = 0; i <= str.length(); i++){
        if (str[i] == 'I'){
            if (str[i + 1] == 'O'){
                if (str[i + 2] == 'I'){
                    i_c++;
                }
            }
        }
    }
    for (int j = 0; j <= str.length(); j++){
        if (str[j] == 'J'){
            if (str[j + 1] == 'O'){
                if (str[j + 2] == 'I'){
                    j_c++;
                }
            }
        }
    }
    cout << j_c << '\n';
    cout << i_c << '\n';
}
