#include <iostream>
#include <string>
#include <stack>
#define MAX  50000000
using namespace std;
int n,m,k;
void solve(string ops, string input){
    int idx[4100], arr[100005] = {};
    stack<int> st;
    for(int i=0;i<m;i++){
        if(ops[i]=='[') st.push(i);
        else if(ops[i]==']'){
            idx[i] = st.top();
            idx[st.top()] = i;
            st.pop();
        }
    }
    int p = 0, c=0,cnt= 0,chk = -1;
    for(int i=0;i<m;i++){
        if(ops[i]=='-') arr[p] = (arr[p]+255)%256;
        else if (ops[i]=='+') arr[p] = (arr[p]+1)%256;
        else if (ops[i]=='<') p = (p-1+n)%n;
        else if (ops[i]=='>') p = (p+1)%n;
        else if (ops[i]=='[' && !arr[p]) i = idx[i];
        else if (ops[i]==']' && arr[p]) chk = max(chk,i), i=idx[i];
        else if (ops[i]==',') arr[p] = (c == k ? 255 : (int)input[c++]);
        if(++cnt == MAX){
            cout << "Loops " << idx[chk] << ' ' << chk << '\n';
            break;
        }
    }
    if(cnt < MAX) cout << "Terminates" << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        string ops,input;
        cin >> n >> m >> k;
        cin >> ops >> input ;
        solve(ops,input);
    }
    return 0; 
}