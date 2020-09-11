#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool is_not_Prime[1000000001];
void make_prime(long long end){
    for(long long i=2;i*i<=end;i++){
        if(is_not_Prime[i]) continue;
        for(long long j = i+i;j<=end;j+=i){
            is_not_Prime[j] =true;
        }
    }
}
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    make_prime(end);
    long long size = end-begin+1;
    long long now;
    answer.resize((int)size,1);
    for(int i=0;i<(int)size;i++){
        now = i+begin;
        if(!is_not_Prime[now]) continue;
        long long mod = 2;
        while(now%mod!=0 && mod*mod <= now) mod++;
        answer[i] = now/mod;
    }
    if(begin == 1) answer[0] = 0;
    return answer;
}
int main(){
    vector<int> v(solution(1,10));
    for(int i=0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    return 0;
}