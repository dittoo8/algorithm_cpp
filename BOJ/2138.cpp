#include <iostream>
#define INF 987654321
using namespace std;
int n;
void swap(string& s, int idx){
    for(int i= idx-1;i<=idx+1;i++){
        if(i < 0 || i>= n) continue;
        if(s[i]=='0') s[i] = '1';
        else s[i] = '0';
    }
}
int swap_cnt(string s, string e ,bool ck){
    int cnt = 0;
    if (ck){
        swap(s,0);
        cnt++;
    }
    for(int i=1;i<n;i++){
        if(s[i-1] != e[i-1]){
            swap(s,i);
            cnt++;
        }
    }
    if (s == e) return cnt;
    else return INF;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    string a, b;
    cin >> a >> b;
    int acnt = swap_cnt(a, b, true);
    int bcnt = swap_cnt(a,b, false);
    int answer;
    if(acnt < bcnt) answer = acnt;
    else answer = bcnt;
    if (answer == INF) answer = -1;
    cout << answer << '\n';
    return 0;
}