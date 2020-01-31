#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    int idx = 0;
    for(int i=0;i<dartResult.length();i++){
        int a = -1;
        if(dartResult[i]=='S') {
            
        } else if (dartResult[i]=='D') {
            v[idx-1] *= v[idx-1];
        } else if (dartResult[i]=='T'){
            v[idx-1] *= v[idx-1]*v[idx-1];
        } else if (dartResult[i]=='*'){
            if(idx-2 >=0) {
                v[idx-1] *=2;
                v[idx-2] *=2;
            } else {
                v[idx-1] *=2;
            }
            
        } else if (dartResult[i]=='#'){
            v[idx-1] *= -1;
        } else {
            if (dartResult[i + 1] == '0') {
                //점수가 10인경우
				v.push_back(10);
				i++;
			}	
			else 
				v.push_back(dartResult[i] - '0');
                //문자니까 int값으로 저장
            
			idx++;
        }
    }
    for(int i=0;i<v.size();i++){
        answer += v[i];
    }
    return answer;
}
int main(){
    cout << solution("1S2D*3T") <<endl;
    return 0;
}