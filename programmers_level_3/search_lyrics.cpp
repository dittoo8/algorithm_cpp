#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    if(a.length()<b.length()) return true;
    else if (a.length()==b.length()){
        if (a < b) return true;
    }
    return false;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> rwords= words;
    int size = rwords.size();
    for(int i=0;i<size;i++){
        reverse(rwords[i].begin(),rwords[i].end());
    }
    sort(words.begin(),words.end(),cmp);
    sort(rwords.begin(),rwords.end(),cmp);
    int len, lo,hi,idx;
    for(string query: queries){
        len = query.length();
        if(query[0]=='?'){ // 접두사
            reverse(query.begin(),query.end());
            idx = query.find_first_of("?");
            for(int i = idx;i<len;i++) query[i]='a';
            lo = lower_bound(rwords.begin(),rwords.end(),query,cmp) - rwords.begin();
            for(int i=idx;i<len;i++) query[i]='z';
            hi = upper_bound(rwords.begin(),rwords.end(),query,cmp)-rwords.begin();
        }else { //접미사
            idx = query.find_first_of("?");
            for(int i = idx;i<len;i++) query[i]='a';
            lo = lower_bound(words.begin(),words.end(),query,cmp) - words.begin();
            for(int i=idx;i<len;i++) query[i]='z';
            hi = upper_bound(words.begin(),words.end(),query,cmp)-words.begin();
        }
        answer.push_back(hi-lo);
    }
    return answer;
}
int main(){
    vector<string> v1 = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> v2 = {"fro??", "????o", "fr???", "fro???", "pro?"};
    vector<int> res = solution(v1,v2);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}