#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> keys;
    keys.insert(words[0]);
    string tmp = words[0];
    answer.push_back(0);
    answer.push_back(0);
    for(int i=1;i<words.size();i++){
        if(keys.find(words[i])!=keys.end() || words[i][0]!=tmp[tmp.length()-1]){
            answer[0] = (i%n)+1;
            answer[1] = (i/n)+1;
            break;
        } else {
            keys.insert(words[i]);
            tmp = words[i];
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    v.push_back("tank");
    v.push_back("kick");
    v.push_back("know");
    v.push_back("wheel");
    v.push_back("land");
    v.push_back("dream");
    v.push_back("mother");
    v.push_back("robot");
    v.push_back("tank");
    vector<int> res;
    res = solution(3,v);
    cout << res[0] <<" , " << res[1] << endl;
    return 0;
}