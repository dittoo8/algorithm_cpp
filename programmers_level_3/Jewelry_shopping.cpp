#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> mp;
    for(int i=0;i<gems.size();i++){
        mp[gems[i]]=0;
    }
    int jSize = mp.size();
    int r = 0, l = 0;
    int last = (int)gems.size();
    int nowcnt = 0;
    answer.push_back(0);
    answer.push_back(last);
    while(true){
        if (nowcnt >= jSize){
            if(mp[gems[l]]-1==0){
                nowcnt--;
            }
            mp[gems[l++]]--;
        } else if (r == last) break;
        else {
            if(mp[gems[r]]==0) nowcnt++;
            mp[gems[r++]]++;
        }
        if(nowcnt == jSize) {
            if (r-l < answer[1]-answer[0]){
                answer[0]=l;
                answer[1]=r;
            }
        }
    }
    answer[0]++;
    return answer;
}
int main(){
    vector<string> v = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<int> ans = solution(v);
    cout << ans[0] <<"," << ans[1] <<endl;
    return 0;
}