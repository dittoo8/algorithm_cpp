#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> st;
    map<string, int> mp;
    for(int i=0;i<gems.size();i++){
        st.insert(gems[i]);
        mp[gems[i]]=0;
    }
    int jSize = st.size();
    int r = 0, l =0;
    int last = (int)gems.size();
    int nowcnt = 0;
    answer.push_back(0);
    answer.push_back(last);
    while(l<last){
        if (nowcnt == jSize) {
            if (r-l < answer[1]-answer[0]){
                answer[0]=l;
                answer[1]=r;
            }
        }
        if (nowcnt < jSize && r+1 < last){
            if(mp[gems[r]]==0) {
               nowcnt++;
            }
            mp[gems[r]]++;
            r++;
        }else if(l+1 < last){
            if(mp[gems[l]]-1 ==0){
                nowcnt--;
            }
             mp[gems[l]]--;
            l++;
        }else if(l+1 == last) break;
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