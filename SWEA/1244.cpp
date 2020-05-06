#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string str;
int n,mx;
int check[1000000][11];

void solve(string s, int len){
    if (len ==n){
        if (atoi(s.c_str())> mx) mx=atoi(s.c_str());
        return;
    }
    if (check[atoi(s.c_str())][len]) return;
    check[atoi(s.c_str())][len] = 1;
    for(int i=0;i<s.length()-1;i++){
        for(int j=i+1;j<s.length();j++){
            char tmp1 = s[i];
            char tmp2 = s[j];
            s[i]= tmp2;
            s[j]=tmp1;
            solve(s,len+1);
            s[i]=tmp1;
            s[j]=tmp2;
        }
    }
}
int main(){
    int tc;
    cin >> tc;
    for(int t=1;t<=tc;t++){
        memset(check,0,sizeof(check));
        mx =0;
        cin >> str;
        cin >> n;
        solve(str, 0);
        cout <<"#" << t <<" " <<mx <<endl;
    }
    return 0;
}
