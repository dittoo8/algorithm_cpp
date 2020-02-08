#include <iostream>
#include <string>
#include <vector>
using namespace std;
int len,max_value;
string str;
bool ck[52];
vector<int> v;
void backtrack(int now){
    if(now == len){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        exit(0);
    }
    string p = "";
    int nowNum = 0;
    for(int i=now; i<=now+1; i++){
        p += str[i];
        nowNum = stoi(p);
        
        if(nowNum > max_value) continue;
        if(ck[nowNum]) continue;
        
        v.push_back(nowNum);
        ck[nowNum] = true;
        backtrack(i+1);
        ck[nowNum] = false;
        v.pop_back();
    }
}
int main() {
    cin >> str;
    len = (int)str.size();
    if(len < 10){
        max_value = len;
    }else{
        max_value = (len - 9) / 2 + 9;
    }
    backtrack(0);
    return 0;
}