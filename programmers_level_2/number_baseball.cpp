#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(vector<vector<int> > baseball) {
    int answer = 0;
    for(int i=123;i<=987;i++){
        string now = to_string(i);
        bool flag = true;
        if (now[0]==now[1]||now[1]==now[2]||now[0]==now[2]) continue;
        if (now[0]=='0'||now[1]=='0'||now[2]=='0') continue;
        for(int j=0;j<baseball.size();j++){
            int strike = 0, ball = 0;
            for(int a=0;a<3;a++){
                for(int b=0;b<3;b++){
                    string num = to_string(baseball[j][0]);
                    if(a==b && now[a]==num[b]){
                        //자리수, 수 모두 같을 때
                        strike++;
                    }else if (now[a]==num[b]){
                        //수만 같을때
                        ball++;
                    }
                }  
            }
            if(strike != baseball[j][1] || ball !=baseball[j][2]){
                flag = false;
                break;
              }
        }
        if(flag){
            answer++;
        }
    }
    return answer;
}
int main(){
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(123);
    v1.push_back(1);
    v1.push_back(1);
    v.push_back(v1);
    vector<int> v2;
    v2.push_back(356);
    v2.push_back(1);
    v2.push_back(0);
    v.push_back(v2);
    vector<int> v3;
    v3.push_back(327);
    v3.push_back(2);
    v3.push_back(0);
    v.push_back(v3);
    vector<int> v4;
    v4.push_back(489);
    v4.push_back(0);
    v4.push_back(1);
    v.push_back(v4);
    cout << solution(v) << endl;
    return 0;
}