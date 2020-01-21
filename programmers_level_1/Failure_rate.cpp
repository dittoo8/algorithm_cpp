#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(const pair<int, double>& a, const pair<int, double>& b){
    if(a.second == b.second) return a.first<b.first;
       return a.second>b.second;
}

void solution(int N, vector<int> stages) {
    vector<int> answer;
    double users[502] = {0,};
    int cnt = stages.size();
    vector<pair<int, double> > res;
    //범위 잘보기
    for(int i=0;i<cnt;i++){
        users[stages[i]]++;
    }
    
    for(int i=1;i<=N;i++){
        printf("%d\n", cnt);
        if(users[i]==0) {
            res.push_back(make_pair(i,0));
            // cnt -= users[i];
        } else {
            res.push_back(make_pair(i,users[i]/cnt));
            printf("%d %f %d\n", i, users[i], cnt);
            cnt -= users[i];
        }
    }
    // sort(res.begin(),res.end(),cmp);
    sort(res.begin(), res.end(),cmp);
    
    for(int i=0;i<res.size();i++){
        answer.push_back(res[i].first);
        // printf("%d %f\n", res[i].first, res[i].second);
        printf("%d ", answer[i]);
    }

}

int main(){
    vector<int> v;
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(6);
    // v.push_back(2);
    // v.push_back(4);
    // v.push_back(3);
    // v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);

    solution(4,v);
}