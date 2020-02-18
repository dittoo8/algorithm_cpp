#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool visit[51] = {false, };
    queue<string> q;
    q.push(begin);
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            string now = q.front();
            if (now == target) return answer;
            q.pop();
            for(int i=0;i<words.size();i++){
                if (visit[i]) continue;
                int cnt = 0;
                for(int j=0;j<now.length();j++){
                    if (now[j] != words[i][j]) cnt++;
                }
                if(cnt==1){
                    visit[i] = true;
                    q.push(words[i]);
                }
            }
        }
        answer++;
        if (answer>=words.size()-1) return 0;
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    v.push_back("hot");
    v.push_back("dot");
    v.push_back("dog");
    v.push_back("lot");
    v.push_back("log");
    v.push_back("cog");
    cout << solution("hit", "cog", v) << endl;
    return 0;
}