#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    if (hand == "right") hand = "R";
    else hand = "L";
    vector<pair<int, int> > v;
    v.resize(10);
    v[0] = make_pair(3,1);
    int i=0,j=0;
    for(int k=1;k<=9;k++){
        if (j==3){
            j=0;
            i++;
        }
        v[k]= make_pair(i,j);
        j++;
    }
    int nowl = -1, nowr = -1;
    for(int i=0;i<numbers.size();i++){
        if (numbers[i]%3 ==2 || numbers[i]==0){
            int nlx,nly,nrx,nry;
            if (nowl == -1 ){
                nlx = 3, nly = 0;
            }else {
                nlx = v[nowl].first;
                nly = v[nowl].second;
            }
            if (nowr == -1 ){
                nrx = 3, nry = 2;
            }else {
                nrx = v[nowr].first;
                nry = v[nowr].second;
            }
            int distl,distr;
            distl = abs(nlx - v[numbers[i]].first)+abs(nly - v[numbers[i]].second);
            distr = abs(nrx - v[numbers[i]].first)+abs(nry - v[numbers[i]].second);
            if (distl < distr){ //왼손이 더 가까움
                answer+='L';
                nowl = numbers[i];
            } else if  (distr < distl){
                answer+='R';
                nowr = numbers[i];
            } else { //거리 같음
                answer+=hand;
                if (hand == "R") nowr = numbers[i];
                else nowl = numbers[i];
            }
        }else if (numbers[i]%3==1){ //왼손사용
            answer+='L';
            nowl = numbers[i];
        }else if (numbers[i]%3==0){ //오른손사용
            answer+='R';
            nowr = numbers[i];
        }
    }
    return answer;
}
int main(){
    vector<int> v = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    cout << solution(v, "right") << endl;
    return 0;
}