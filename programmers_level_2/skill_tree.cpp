#include <iostream>
#include <string>
#include <vector>

using namespace std;
int check[27];
vector<int> a[27];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0;i<skill.length();i++){
        check[skill[i] - 'A'] = i+1;
    }
    int temp = 0;
    for(int i=0;i<skill_trees.size();i++){
        int temp = 0;
        string now = skill_trees[i];
        int pos = 1;
        for(int j=0;j<now.length();j++){
            if(check[now[j]-'A']!=0){
                if(check[now[j]-'A'] == pos) {
                    pos++;
                } else temp = -1;
            }
        }
        if (temp == 0) answer++;
    }
    
    return answer;
}
int main(){
    vector<string> s;
    s.push_back("BACDE");
    s.push_back("CBADF");
    s.push_back("AECB");
    s.push_back("BDA");
    cout << solution("CBD",s) <<endl;
    return 0;
}