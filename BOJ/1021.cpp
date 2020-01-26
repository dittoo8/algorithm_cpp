#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
int n,m;
deque<int> dq;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
    int res = 0;
    for(int i=0;i<m;i++){
        int idx;
        scanf("%d", &idx);
        int cur = 1;
        for(deque<int>::iterator iter = dq.begin(); iter <dq.end();iter++){
            if(*iter ==idx) break;
            cur++;
        }
        int left = cur - 1;
        int right = dq.size() - cur + 1;
        if (left <right) {
            for(int j=1;j<=left;j++){
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
                res++;
            }
            dq.pop_front();
        } else {
            for(int j=1;j<=right;j++){
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
                res++;
            }
            dq.pop_front();
        }
    }

    printf("%d", res);
}