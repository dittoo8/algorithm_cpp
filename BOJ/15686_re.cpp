#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int n,m,ans = 1e9;
vector<pair<int, int> > chi; //치킨집 위치
vector<pair<int, int> > h; //집 위치
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // 맵은 풀이에 이용하지 않으므로 값만 입력받음
            int tmpa;
            scanf("%d", &tmpa);
            if(tmpa==1) {
                h.push_back(make_pair(i,j));
            }else if(tmpa==2){
                chi.push_back(make_pair(i,j));
            }
        }
    }
    //next permutation 에 사용할 배열
    vector<int> check((int)chi.size());
    for(int i=0;i<m;i++){
        check[i]=1;
    }
    sort(check.begin(),check.end());
    do {
        int distsum =0;
        for(int i=0;i<h.size();i++){
            int min = 1e8;
            for(int j=0;j<chi.size();j++){
                if (check[j]==0) continue;
                int now = abs(chi[j].first-h[i].first)+abs(chi[j].second-h[i].second);
                if (now < min) min = now;
            }
            distsum+=min;
        }
        if(distsum < ans) ans = distsum;
    }while (next_permutation(check.begin(),check.end()));
    printf("%d\n", ans);
    return 0;
}