#include <cstdio>
#include <stack>
#define MAX 500001
using namespace std;
int n;
int res[MAX];
stack<pair<int, long long> > st;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long long cur;
        scanf("%lld", &cur);
        while(!st.empty()){
            if(st.top().second > cur){
                res[i]=st.top().first;
                break;
            }else st.pop();
        }
        if(st.empty()) res[i]=0;
        st.push(make_pair(i,cur));
        
    }

    for(int i=1;i<=n;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
    return 0;
}