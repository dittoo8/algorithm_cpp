#include <iostream>
#include <algorithm>
using namespace std;
int n;
int score[51][10], per[9] = {0,1,2,3,4,5,6,7,8};
int ru[10]={0};
int move(int cnt, int idx){
    int tmp = 0;
    for(int k=0;k<9;k++){
        if(k==idx) continue;
        if(ru[k]==0)continue;
        ru[k]+=cnt;
        if(ru[k]>=4){
            tmp++;
            ru[k]=0;
        }
    }
    ru[idx]+=cnt;
    if(ru[idx]>=4){
        tmp++;
        ru[idx]=0;
    }
    return tmp;
}
int solve(){
    int tmpAns = 0;
    int outCnt = 0;
    int idx = 0;
    int inning = 0;
    while(true){
        int nowScore = score[inning][per[idx%9]];
        if (nowScore == 0){
            outCnt++;
            if (outCnt == 3){
                inning++;
                fill(&ru[0], &ru[8]+1,0);
                if(inning == n) break;
                outCnt = 0;
            }
        }else {
            tmpAns+=move(nowScore,per[idx%9]);
        }
        idx++;
    }
    return tmpAns;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            cin >> score[i][j];
        }
    }
    int ans =0;
    do {
        if (per[3]!=0) continue;
        int tmp = solve();
        if (tmp > ans ) ans = tmp;
    }while(next_permutation(per,per+9));
    cout << ans << '\n';
    return 0;
}