#include <iostream>
#include <vector>
using namespace std;
int cover;
int ck(int s, int e){
    if (s+cover >e) return 1;
    int cur = s, cnt = 0;
    while(true){
        if (cur+cover > e) break;
        cur+=cover;
        cnt++;
    }
    if (e-cur >=0) cnt++;
    return cnt;
}
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    cover = w*2+1;
    int start = 1;
    for(int i=0;i<stations.size();i++){
        if(stations[i]-start>w){
            answer+=ck(start,stations[i]-w-1);
        }
        start =stations[i]+w+1;
    }
    if (start <= n){
        answer += ck(start,n);
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    v.push_back(4);
    v.push_back(11);
    cout << solution(11,v,1) <<endl; 
    return 0;
}