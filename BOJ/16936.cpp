#include <cstdio>
#include <set>
#include <vector>
using namespace std;
int n;
long long a[101];
bool ck[101];
vector<long long> v;
set<long long> st;
bool dfs(long long x, int cnt){
    if (cnt == n){
        for(int i=0;i<v.size();i++){
            printf("%lld ", v[i]);
        }
        return true;
    }
    if(x%3 == 0 && st.find(x/3)!= st.end()){
        v.push_back(x/3);
        st.erase(x/3);
        dfs(x/3, cnt+1);
        v.pop_back();
        st.insert(x/3);
    }
    if(st.find(x*2)!=st.end()){
        v.push_back(x*2);
        st.erase(x*2);
        dfs(x*2,cnt+1);
        st.insert(x*2);
        v.pop_back();
    }
    return false; 
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
        st.insert(a[i]);
    }
    for(int i=0;i<n;i++){
        v.push_back(a[i]);
        if (dfs(a[i],1)) break;
        v.pop_back();
    }
    return 0;
}