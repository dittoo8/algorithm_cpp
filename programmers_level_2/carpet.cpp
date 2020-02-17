#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> solution(int brown, int red) {
    vector<int> answer;
    int a, b;
    for(int i=1;i<=red;i++){
        int newRed,newBrown;
        if (red%i!=0) continue;
        newRed = red/i;
        newBrown = newRed*2+i*2+4;
        if (newBrown == brown){
            answer.push_back(newRed+2);
            answer.push_back(i+2);
            break;
        }
    }
    return answer;
}
int main(){
    vector<int> v;
    v =solution(10,2);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " " ;
    }
    return 0;
}