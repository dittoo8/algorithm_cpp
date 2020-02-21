#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends;
    friends.push_back('A');
    friends.push_back('C');
    friends.push_back('F');
    friends.push_back('J');
    friends.push_back('M');
    friends.push_back('N');
    friends.push_back('R');
    friends.push_back('T');
    sort(friends.begin(),friends.end());
    do{
        bool check = true;
        for(int i=0;i<data.size();i++){
            char l = data[i][0];
            char r = data[i][2];
            char sign = data[i][3];
            int dist = data[i][4]-'0'+1;
            int lIdx, rIdx;
            for(int j=0;j<8;j++){
                if(friends[j]==l) lIdx = j;
                if(friends[j]==r) rIdx = j;
            }
            switch(sign){
            case '=':
                if(abs(lIdx-rIdx)!=dist) check = false;
                break;
            case '<':
                if(abs(lIdx-rIdx)>=dist) check = false;
                break;
            case '>':
                if(abs(lIdx-rIdx)<=dist) check = false;
                break;
        }
        if(!check) break;
        }
        if(check) answer++;
    }while (next_permutation(friends.begin(),friends.end()));
    return answer;
}
int main(){
    vector<string> v;
    v.push_back("N~F=0");
    v.push_back("R~T>2");
    cout << solution(2,v) << endl;
    return 0;
}