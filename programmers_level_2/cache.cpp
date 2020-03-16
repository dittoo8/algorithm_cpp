#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <queue>
#include <algorithm>
using namespace std;
bool cmp(pair<int, string> &a, pair<int, string> &b){
    //내림차순 정렬
    return a.first > b.first;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize ==0){
        return cities.size()*5;
    }
    for(int i=0;i<cities.size();i++){
        transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::tolower);
    }
    vector<pair<int, string> > v;
    for(int i=0;i<cities.size();i++){
        bool ck=false;
        if (v.size()) { //v.size()가 0이 아닐때
            for(int j=0;j<v.size();j++){
                if(v[j].second == cities[i]){
                    //cache 에 존재할 때
                    ck=true;
                    v[j].first=-i;
                    answer+=1;
                    break;
                }
            }
        }
        if(!ck){
            if(v.size()==cacheSize){
                v.pop_back();
            }
            v.push_back(make_pair(i,cities[i]));
            answer+=5;
        }
        sort(v.begin(),v.end(),cmp);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<string> v;
    v.push_back("Jeju");
    v.push_back("Pangyo");
    v.push_back("Seoul");
    v.push_back("NewYork");
    v.push_back("LA");
    v.push_back("Jeju");
    v.push_back("Pangyo");
    v.push_back("Seoul");
    v.push_back("NewYork");
    v.push_back("LA");
    cout << solution(3,v) << endl;
    return 0;
}