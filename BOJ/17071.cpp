#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int n,k;
bool ck[MAX][2];
int main(){
    scanf("%d %d", &n, &k);
    if(n==k) printf("0\n");
    else {
        queue<int> q;
        q.push(n);
        ck[n][0]=true;
        int ans =1;
        while(int s = q.size()){
            k+=ans;
            if(k>500000) break;
            while(s--){
                int now = q.front();
                q.pop();
                for(int i=0;i<3;i++){
                    int next = now;
                    switch (i){
                        case 0: next-=1; break;
                        case 1: next+=1; break;
                        case 2: next*=2; break;
                    }
                    if(0<=next && next <=500000 && !ck[next][ans%2]){
                        ck[next][ans%2]=true;
                        q.push(next);
                    }
                }
            }
            if(ck[k][ans%2]){
                printf("%d\n",ans);
                return 0;
            }
            ans++;
        }
        printf("-1\n");
    }
    return 0;
}