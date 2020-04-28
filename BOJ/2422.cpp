#include<iostream>
#include<vector>
#define MAX 200 + 1
using namespace std;
int N, M, Answer;
bool Visit[MAX][MAX];
bool Select[MAX];
vector<int> V;
bool isPossible(){
    if (Visit[V.at(0)][V.at(1)] || Visit[V.at(1)][V.at(2)] || Visit[V.at(0)][V.at(2)]) {
        return false;
    }
    return true;
}
void backtrack(int Idx, int Cnt){
    if (Cnt == 3){
        if (isPossible()) Answer++;
        return;
    }
    for (int i = Idx; i <= N; i++){
        if (Select[i] == true) continue;
        Select[i] = true;
        V.push_back(i);
        backtrack(i, Cnt + 1);
        Select[i] = false;
        V.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        Visit[a][b] = true;
        Visit[b][a] = true;
    }
    backtrack(1,0);
    cout << Answer <<endl;
    return 0;
}