#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;
    vector<pair<string, int> > v;
    // v.push_back(make_pair(clothes[0][1],1));
    for(int i=0;i<clothes.size();i++){
        bool check = false;
        for(int j=0;j<v.size();j++){
            if(v[j].first == clothes[i][1]){
                cout << "count ++ : " << clothes[i][1] << endl;;
                v[j].second++;
                check = true;
                break;
            }

        }
        if(!check){
            cout << "push_back : " << clothes[i][1] << endl;
            v.push_back(make_pair(clothes[i][1],1));
        }
    }
    for(int i=0;i<v.size();i++){
        cout << v[i].second << endl;
        answer *= (v[i].second + 1);
        cout << "answer : " << answer << endl;
    }
    answer-=1;
    return answer;
}
int main(){
    vector<vector<string> > v;
    vector<string> v1;
    v1.push_back("yellow_hat");
    v1.push_back("headgear");
    vector<string> v2;
    v2.push_back("blue_sunglasses");
    v2.push_back("eyewear");
    vector<string> v3;
    v3.push_back("green_turban");
    v3.push_back("headgear");
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    
    cout << solution(v) << endl;
    return 0;
}