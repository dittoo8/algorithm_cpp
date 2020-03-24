#include <iostream>
#include <string>
using namespace std;
int n;
char op[9];
bool c[10];
string mn,mx;
bool possible(int i, int j, char k){
    if (k== '<') return i<j;
    if (k== '>') return i>j;
    return true;
}
void solve(int cnt, string s){
    if(cnt == n+1){
        if (!mn.size()) mn=s;
        else mx = s;
        return;
    }
    for(int i=0;i<10;i++){
        if (c[i]) continue;
        if(cnt==0 || possible(s[cnt-1],i+'0',op[cnt-1])){
            c[i]=true;
            solve(cnt+1, s+to_string(i));
            c[i]=false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> op[i];
    }
    solve(0,"");
    cout << mx <<endl;
    cout << mn << endl;
    return 0;
}