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
    v.resize(13);
    v[0] = make_pair(3,1);
    int i=0,j=-1;
    for(int k=1;k<=12;k++){
        j++;
        if (j==3){
            j=0;
            i++;
        }
        if (k==11) continue;
        v[k]= make_pair(i,j);
    }
    pair<int, int> l,r;
    l = v[10];
    r = v[12];
    for(int i=0;i<numbers.size();i++){
        if (numbers[i]%3 ==2 || numbers[i]==0){
            int distl,distr;
            distl = abs(l.first - v[numbers[i]].first)+abs(l.second - v[numbers[i]].second);
            distr = abs(r.first - v[numbers[i]].first)+abs(r.second - v[numbers[i]].second);
            if (distl < distr){ //왼손이 더 가까움
                answer+='L';
                l = v[numbers[i]];
            } else if  (distr < distl){
                answer+='R';
                r = v[numbers[i]];
            } else { //거리 같음
                answer+=hand;
                if (hand == "R") r = v[numbers[i]];
                else l = v[numbers[i]];
            }
        }else if (numbers[i]%3==1){ //왼손사용
            answer+='L';
            l = v[numbers[i]];
        }else if (numbers[i]%3==0){ //오른손사용
            answer+='R';
            r = v[numbers[i]];
        }
    }
    return answer;
}
int main(){
    vector<int> v = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    cout << solution(v, "right") << endl;
    return 0;
}