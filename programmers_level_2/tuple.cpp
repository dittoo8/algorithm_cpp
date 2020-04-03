#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ck[1000001];
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first>b.first;
}
vector<int> solution(string s) {
    vector<int> answer;
    s=s.substr(1,s.length()-2);
    int len = 0;
    string tmp ="";
    int max=0;
    for(int i=0;i<s.length();i++){
        if (s[i]=='{') continue;
        if (s[i]=='}') {
            int n = stoi(tmp);
            if (n>max) max=n;
            ck[n]++;
            tmp = "";
            i+=2;
        }else if (s[i]==','){
            int n = stoi(tmp);
            if (n>max) max=n;
            ck[n]++;
            tmp = "";
        } else {
            tmp+=s[i];
        }
    }
    vector<pair<int, int> > p;
    for(int i=0;i<=max;i++){
        if(ck[i]) p.push_back(make_pair(ck[i],i));
    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<p.size();i++){
        answer.push_back(p[i].second);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    v = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    for(int i=0;i<v.size();i++){
        cout << v[i] <<" ";
    }
    return 0;
}