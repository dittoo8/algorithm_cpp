#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<int> v;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    if (prev_permutation(v.begin(),v.end())){
        for(int i=0;i<v.size();i++){
            printf("%d ", v[i]);
        }
    } else {
        printf("-1\n");
    }
    return 0;
}