#include <cstdio>
#include <deque>
using namespace std;
int n;
deque<pair<int ,int> > dq;
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d", &a);
        dq.push_back(make_pair(i,a));
    }
    int now = 1;
    int next = dq.front().second;
    dq.pop_front();
    printf("%d ", now);
    while(!dq.empty()){
        if (next > 0) {
            for(int i=0;i<next-1;i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            
        } else {
            for(int i=next;i<0;i++){
                //범위계산 잘하기
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        now = dq.front().first;
        next = dq.front().second;
        printf("%d ",now);
        dq.pop_front();
        
    }
    return 0;
}