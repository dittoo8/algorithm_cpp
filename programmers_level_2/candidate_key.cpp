#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
bool possi(vector<int> &vec, int now){
    for(int i=0;i<vec.size();i++){
        if((vec[i]&now)==vec[i]) return false;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    vector<int> ans;
    int n=relation.size();
    int m =relation[0].size();
    for(int i=1;i<(1<<m);i++){
        set<string> s;
        for(int j=0;j<n;j++){
            string now = "";
            for(int k=0;k<m;k++){
                if(i&(1<<k))now+=relation[j][k];
            }
            s.insert(now);
        }
        if(s.size()==n &&possi(ans,i))ans.push_back(i);
    }
    
    return ans.size();
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<string> > v;
    vector<string> v1;
    v1.push_back("100");
    v1.push_back("ryan");
    v1.push_back("music");
    v1.push_back("2");
    vector<string> v2;
    v2.push_back("200");
    v2.push_back("apeach");
    v2.push_back("math");
    v2.push_back("2");
    vector<string> v3;
    v3.push_back("300");
    v3.push_back("tube");
    v3.push_back("computer");
    v3.push_back("3");
    vector<string> v4;
    v4.push_back("400");
    v4.push_back("con");
    v4.push_back("computer");
    v4.push_back("4");
    vector<string> v5;
    v5.push_back("500");
    v5.push_back("muzi");
    v5.push_back("music");
    v5.push_back("3");
    vector<string> v6;
    v6.push_back("600");
    v6.push_back("apeach");
    v6.push_back("music");
    v6.push_back("2");
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    cout <<solution(v) << endl;
    return 0;
}