#include <iostream>
#include <map>
#include <queue>
#include <array>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    array<string, 3> str;
    for(int i=0;i<3;i++){
        int n;
        cin >> n;
        if (n > 0) cin >> str[i];
        else str[i] = "";
    }
    array<string, 3> ans;
    for(int i=0;i<3;i++){
        for(int j=0;j<str[i].length();j++){
            ans[str[i][j]-'A']+=str[i][j];
        }
    }
    map<array<string, 3>, int> d;
    queue<array<string, 3> > q;
    q.push(str);
    d[str]=0;
    while(!q.empty()){
        auto now = q.front();
        if (now == ans){
            break;
        }
        q.pop();
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (i == j) continue;
                if (now[i].length() == 0) continue;
                array<string, 3> next(now);
                next[j].push_back(next[i].back());
                next[i].pop_back();
                if (d.find(next) == d.end()) {
                    d[next] = d[now]+1;
                    q.push(next);
                }
            }
        }
    }
    cout << d[ans] << '\n';
    return 0;
}