#include <cstdio>
int tap[100] = {0,};
int ans = 0;

using namespace std;
int main(){
    int n, s;
    scanf("%d %d",&n, &s);
    //스케쥴 순서
    int items[s];
    // 멀티탭 구멍 개수
    for(int i=0;i<s;i++){
        scanf("%d", &items[i]);
    }
    for(int i=0;i<s;i++){
        bool plugged = false;
        for(int j=0;j<n;j++){
           //멀티탭에 꽂혀있는지
           if (tap[j]==items[i]) {
               plugged = true;
               break;
           }
        }
        if(plugged) continue;
        //꽂혀있으면 이번 아이템 패스
        for (int j=0;j<n;j++){
            //빈 곳 있으면 체크하고 꽂음
            if (tap[j]==0) {
                tap[j] = items[i];
                plugged = true;
                break;
            }
        }
        if(plugged) continue;
        //꽂았으니 패스.

        int idx, devIdx = -1;
        for (int j=0;j<n;j++){
            int lastIdx = 0;
            for(int k = i+1;k<s;k++){
                if(tap[j]==items[k]) break;
                lastIdx++;
            }
            if(lastIdx > devIdx){
                idx = j;
                devIdx = lastIdx;
            }
        }
        printf("%d 번째 sequence에서 뽑는 idx, val : %d , %d , 넣는 val : %d \n", i,idx,tap[idx], items[i] );
        tap[idx] = items[i];
        ans++;



    }
    printf("%d",ans);
    return 0;
    
}