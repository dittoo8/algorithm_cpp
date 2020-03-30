#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v[26];
bool ck[26];
int res,n;
void backtrack(int idx){
    if (idx ==n){
        for(int i=0;i<26;i++){
            int r = v[i].size();
            bool c = false;
            for(int j=0;j<r;j++){
                if(ck[v[i][j]]){
                    c = true;
                    break;
                }
            }
            if(!c) return;
        }
        res++;
        return;
    }
    ck[idx]=true;
    backtrack(idx+1);
    ck[idx]=false;
    backtrack(idx+1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        for(int k=0;k<26;k++){
            v[k].clear();
        }
        memset(ck,0,sizeof(ck));
        res=0;
        cin >> n;
        for(int k=0;k<n;k++){
            string str;
            cin >> str;
            for(int j=0;j<str.length();j++){
                int idx = str[j]-'a';
                v[idx].push_back(k);
            }
        }
        backtrack(0);
        cout << "#"<<i<<" "<<res<<endl;
    }
    return 0;
}