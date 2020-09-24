#include <iostream>
#include <deque>
#include <string>
using namespace std;
string target, str;
deque<char> left_dq, right_dq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> target >> str;
    int l = 0, r = str.length()-1;
    while(true){
        bool ck = false;
        while(l<=r){
            left_dq.push_back(str[l]);
            l++;
            if(left_dq.size()>= target.length()){
                bool find_t = true;
                for(int i=0;i<target.size();i++){
                    if(target[i]!=left_dq[left_dq.size()-target.size()+i]){
                        find_t = false;
                        break;
                    }
                }
                if(find_t) ck = true;
            }
            if(ck){
                for(int i=0;i<target.length();i++){
                    left_dq.pop_back();
                }
                break;
            }
        }
        if(!ck) break;
        ck = false;
        while(l<=r){
            right_dq.push_front(str[r]);
            r--;
            if(right_dq.size()>=target.length()){
                bool find_t = true;
                for(int i=0;i<target.length();i++){
                    if(target[i]!=right_dq[i]){
                        find_t = false;
                        break;
                    }
                }
                if(find_t) ck = true;
            }
            if(ck){
                for( int i=0;i<target.size();i++){
                    right_dq.pop_front();
                }
                break;
            }
        }
    }
    string answer = "";
    for(int i=0;i<left_dq.size();i++) answer.push_back(left_dq[i]);
    for(int i=0;i<right_dq.size();i++) answer.push_back(right_dq[i]);
    while(answer.find(target)< 30000){
        answer.erase(answer.find(target),target.size());
    }
    if(!answer.empty()) cout << answer << '\n';
    return 0;
}