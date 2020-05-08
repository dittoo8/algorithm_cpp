#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    int qSize = (int)queries.size();
    answer.resize(qSize,0);
    for(int i=0;i<queries.size();i++){
        for(int j=0;j<words.size();j++){
            if (queries[i].length()!=words[j].length())continue;
            bool ck=true;
            for(int k=0;k<words[j].length();k++){
                if (queries[i][k]=='?') continue;
                if (queries[i][k]!=words[j][k]) {
                    ck=false;
                    break;
                }
            }
            if(ck) answer[i]++;
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> res;
    vector<string> v1 = {
        "frodo","front","frost","frozen", "frame","kakao"
    };
    vector<string> v2 = {
        "fro??","????o","fr???","fro???", "pro?"
    };
    res = solution(v1,v2);
    for(int i=0;i<res.size();i++){
        cout << res[i] <<", ";
    }
    return 0;
}