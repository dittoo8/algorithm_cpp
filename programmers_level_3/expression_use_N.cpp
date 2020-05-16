#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    const int MIN = 8;
    vector<set<int> > s(MIN);
    int tmp = N;
    for(int i=0;i<s.size();i++){
        s[i].insert(tmp);
        tmp*=10;
        tmp+=N;
    }
    for(int i=0;i<MIN;i++){
        for(int j=0;j<i;j++){
            for(const auto &op1 : s[j]){
                for(const auto &op2:s[i-j-1]){
                    s[i].insert(op1+op2);
                    s[i].insert(op1-op2);
                    s[i].insert(op1*op2);
                    if(op2!=0) s[i].insert(op1/op2);
                }
            }
        }
        if(s[i].find(number)!=s[i].end()){
            answer=i+1;
            break;
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solution(5,12) <<endl;
    return 0;
}