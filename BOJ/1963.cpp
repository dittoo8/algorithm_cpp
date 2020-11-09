#include <iostream>
#include <string>
#include <queue>
#define MAX 10000
using namespace std;
int ck_Prime[MAX];
void check_Prime(){
    for(int i=2;i*i<=MAX;i++){
        if(ck_Prime[i]) continue;
        for(int j= i+i;j<=MAX;j+=i){
            ck_Prime[j] = true;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    check_Prime();
    int visit[MAX], tc;
    cin >> tc;
    string num,tar;
    while(tc--){
        cin >> num >> tar;
        queue<pair<string, int> > q;
        fill(&visit[0], &visit[MAX]+1,-1);
        visit[stoi(num)] = 0;
        q.push(make_pair(num,0));
        bool fin = false;
        while(!q.empty()){
            string now = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(now == tar){
                cout << cnt << '\n';
                fin = true;
                break;
            }
            for(int k=0;k<4;k++){
                for(int i=0;i<10;i++){
                    if(k==0 && i ==0) continue; // 천의자리 0인 경우 pass
                    if(now[k] == i) continue; //현재 자리수와 i 가 같은 수 일 때 pass
                    string next = now;
                    next[k] = char(i+'0');
                    if(visit[stoi(next)]!= -1) continue;
                    if(!ck_Prime[stoi(next)]){
                        q.push(make_pair(next,cnt+1));
                        visit[stoi(next)] = cnt+1;
                    }
                }
            }
        }
        if(!fin){
            cout << "Impossible" << '\n';
        }
    }
    return 0;
}