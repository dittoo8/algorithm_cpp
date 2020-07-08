#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first) return a.second < b.second;
    return a.first  > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> summap; // key : genre, value : allcnt
    map<string, vector<pair<int, int> > > genmap; // key : genre, value : (playscnt, playsidx)
    for(int i=0;i<genres.size();i++){
        summap[genres[i]]+=plays[i];
        genmap[genres[i]].push_back(make_pair(plays[i],i));
    }
    vector<pair<int, string > > orders;
    for(auto x : summap){
        orders.push_back(make_pair(x.second, x.first));
    }
    sort(orders.begin(),orders.end());
    while(orders.size()>0){
        pair<int, string> now = orders.back();
        orders.pop_back();
        vector<pair<int, int> > nowv = genmap[now.second];
        sort(nowv.begin(),nowv.end(),cmp);
        int last = nowv.size() >= 2 ? 2 : (int)nowv.size();
        for(int i=0;i<last;i++){
            answer.push_back(nowv[i].second);
        }
    }
    return answer;
}
int main(){
    vector<string> v1 = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> v2 = {500, 600, 150, 800, 2500};
    vector<int> res = solution(v1,v2);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}