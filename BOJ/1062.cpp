#include <iostream>
#include <string>
using namespace std;
int n,k,ans;
string str[51];
bool ck[27];
int readCnt(){
    int cnt=0;
    for(int i=0;i<n;i++){
        bool flag = true;
        int len = str[i].size();
        for(int j=0;j<len;j++){
            if(!ck[str[i][j]-'a']) flag = false;
            if (!flag) break;
        }
        if(flag) cnt++;
    }
    return cnt;
}
void solve(int cur, int cnt){
    if (cnt==k-5){
        int read = readCnt();
        if(ans < read) ans = read;
        return;
    }
    for(int i=cur;i<26;i++){
        if(ck[i]) continue;
        ck[i]=true;
        solve(i+1,cnt+1);
        ck[i]=false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> s;
        s = s.substr(4,s.length()-4);
        if(s.length()>0){
            str[i] = s;
        }
    }
    if(k==26) ans = n;
    else if (k>=5){
        ck['a'-'a']=true;
        ck['n'-'a']=true;
        ck['t'-'a']=true;
        ck['i'-'a']=true;
        ck['c'-'a']=true;
        solve(0,0);
    }
    cout << ans;
    return 0;
}