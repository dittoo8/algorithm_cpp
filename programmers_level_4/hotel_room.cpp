#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> mp;
long long dfs(long long  x){
    if(!mp[x]) return x;
    return mp[x] = dfs(mp[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++){
        if (!mp[room_number[i]]){
            answer.push_back(room_number[i]);
            mp[room_number[i]]=dfs(room_number[i]+1);
        }else {
            long long next = dfs(room_number[i]+1);
            answer.push_back(next);
            mp[next]=dfs(next+1);
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<long long> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    vector<long long> r;
    r = solution(10,v);
    for(long long i=0;i<r.size();i++){
        cout << r[i]<<" ";

    }
    return 0;
}