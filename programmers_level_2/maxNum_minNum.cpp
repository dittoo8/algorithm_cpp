#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    string tempNum = "";
    for(int i=0;i<s.length();i++){
        
        if(s[i]=='-'){
            tempNum+='-';
        }
        else if(s[i]>='0' &&s[i]<='9'){
            tempNum+=s[i];
        } else {
            v.push_back(atoi(tempNum.c_str()));
            tempNum="";
        }
    }
    if(tempNum!=""){
        v.push_back(atoi(tempNum.c_str()));
    }
    sort(v.begin(),v.end());
    answer+= to_string(v[0]);
    answer+=" ";
    int last = (int)v.size();
    answer+=to_string(v[last-1]);
    return answer;
}
int main(){
    cout << solution("1 2 3 4") <<endl;
    return 0;
}