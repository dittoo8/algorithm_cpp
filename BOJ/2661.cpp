#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> v;
bool check(){
    int len = (int)v.size();
    for(int i=1;i<=len/2;i++){
        string s1 = "";
        string s2 = "";
        for(int j=0;j<i;j++){
            s1+=to_string(v[len - (2*i)+j]);
            s2+=to_string(v[len-i+j]);
        }
        if(s1==s2) return false;
    }
    return true;
}
void dfs(int cnt){
    if (cnt == n){
        for(int i=0;i<v.size();i++){
            cout << v[i];
        }
        cout << endl;
        exit(0);
    }
    for(int i=1;i<=3;i++){
        v.push_back(i);
        if(check()){
            dfs(cnt+1);
        }
        v.pop_back();
    }
}
int main(){
    cin >> n;
    dfs(0);
    return 0;
}