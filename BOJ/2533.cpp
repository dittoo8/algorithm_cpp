#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;
int n;
vector<int> v[MAX];
vector<int> child[MAX];
int d[MAX][2];
bool visit[MAX];
void getchild(int now){
    visit[now] = true;
    for(int i=0;i<v[now].size();i++){
        int next = v[now][i];
        if(!visit[next]){
            child[now].push_back(next);
            getchild(next);
        }
    }
}
int dp(int curr,bool check){
    if(d[curr][check]!=0) return d[curr][check];
    if(child[curr].size()==0) return d[curr][check] = check;
    if(check){
        //현재 노드가 얼리어답터일때,
        int ans = 0;
        for(int i=0;i<child[curr].size();i++){
            int next = child[curr][i];
            ans+= min(dp(next,true),dp(next,false));
        }
        return d[curr][check] = ans+1;

    } else {
        //현재 노드가 얼리어답터가 아닐때
        int ans =0;
        for(int i=0;i<child[curr].size();i++){
            int next = child[curr][i];
            ans+= dp(next,true);
        }
        return d[curr][check] = ans;
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int tempA, tempB;
        cin >> tempA >> tempB;
        v[tempA].push_back(tempB);
        v[tempB].push_back(tempA);
    }
    getchild(1);
    cout << min(dp(1,false),dp(1,true)) <<endl;
    return 0;
}