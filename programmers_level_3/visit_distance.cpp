#include <iostream>
#include <string>
using namespace std;
bool visit[11][11][11][11];
int solution(string dirs) {
    int answer = 0;
    int nowi=5, nowj=5;
    for(int i=0;i<dirs.size();i++){
        int nexti=nowi,nextj=nowj;
        if (dirs[i]=='U'){
            nexti--;
        }else if (dirs[i]=='D'){
            nexti++;
        }else if (dirs[i]=='R'){
            nextj++;
        }else {
            nextj--;
        }
        if(nexti < 0 || nexti > 10 ||nextj < 0 || nextj > 10) continue;
        if (!visit[nowi][nowj][nexti][nextj]){
            visit[nowi][nowj][nexti][nextj]=true;
            visit[nexti][nextj][nowi][nowj]=true;
            answer++;
        }
        nowi = nexti;
        nowj = nextj;
    }
    return answer;
}
int main(){
    cout << solution("ULURRDLLU") <<endl;
    return 0;
}