#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int b[1001],n;
    for(int tc=1;tc<=10;tc++){
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &b[i]);
        }
        int ans =0;
        int  temp = 0;
        for(int i=2;i<n-2;i++){
            if ((temp = b[i] - max(max(b[i - 1], b[i - 2]), max(b[i + 1], b[i + 2]))) > 0) {
				ans += temp;
			}
        }
        printf("#%d %d\n", tc,ans);
    }
    return 0;
}