#include <cstdio>
using namespace std;
int n,a[11],ans;
bool ck[11];
void backtrack(int cnt, int sum){
    if (cnt == n-2) {
        if (sum > ans) ans = sum;
        return;
    }
    for(int i=1;i<n-1;i++){
        if (ck[i]==false){
            int l =i-1, r=i+1;
            while(ck[l] && l>0) l--;
            while(ck[r] && r<n-1) r++;
            ck[i]=true;
            backtrack(cnt+1, sum + a[l]*a[r]);
            ck[i]=false;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    backtrack(0,0);
    printf("%d\n",ans);
    return 0;
}