#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 501;
int n;
pair<int, int> line[MAX];
int tmp[MAX];
int LIS(){
    int idx = 0, removeCnt = 0;
    tmp[idx]=line[0].second;
    for(int i=1;i<n;i++){
        if(tmp[idx]<line[i].second){ // LIS 추가
            tmp[++idx] = line[i].second;
        }else {
            int idx2 = lower_bound(tmp,tmp+idx,line[i].second) - tmp;
            tmp[idx2] = line[i].second;
            removeCnt++;
        }
    }
    return removeCnt;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &line[i].first, &line[i].second);
    }
    sort(line,line+n);
    printf("%d\n", LIS());
    return 0;
}