#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int getMinLength(int start,string name){
    
    int left = name.at(start);
    int right = name.at(start);
    int depth = 0;
    
    while(true){
        if(left == 65 || right == 65){
            break;
        }
        depth++;
        right++;
        left--;
        
        if(right > 90){
            right = 65;
        }
    }
    return depth;
}
int solution(string name) {
    
    int answer = 0;
    
    string str="";
    
    int max = name.size()-1;
    int min = 0;
    
    for(int i=0;i<name.size();i++){
        str+="A";
    }
    
    int start = 0;
    int left,right;
    
    while(true){
        left = start;
        right = start;
        if(name.at(start) != 'A'){ 
            answer += getMinLength(start,name); // 위 / 아래로 움직임
            name.replace(start,1,"A");
        }
        if(str == name){
            break;
        }
        int mov = 0;
        while(true){ // 좌 / 우로 움직임
            left--;
            right++;
            mov++;
            if(left < min){
                left = max;
            }
            if(right > max){
                right = min;
            }
            if(name.at(right) != 'A'){
                answer += mov;
                start = right;
                break;
            }
            if(name.at(left) != 'A'){
                answer += mov;
                start = left;
                break;
            }
        }
    }
    return answer;
}
int main(){
    cout << solution("JEROEN") << endl;
    return 0;
}