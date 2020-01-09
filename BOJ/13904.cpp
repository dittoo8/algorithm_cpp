#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector< pair<int, int> > hwV;
int list[1001] = {0,};
bool cmp(const pair<int, int> &a, const pair<int, int> &b){ 
    return a.first > b.first;
}
int main(){
    int n;
    int a, b;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &b, &a);
        hwV.push_back(make_pair(a,b));
    }
    sort(hwV.begin(),hwV.end(), cmp);

    for(int i=0;i<n;i++){
        int lastDay = hwV[i].second-1;
        for(int j=lastDay;j>=0;j--){

            if(list[j]==0) {
                list[j] = hwV[i].first;
                 break;
            }
            
        }
    }
    int sum = 0;
    for(int i=0;i<=1001;i++){
        sum+=list[i];
    }
    printf("%d", sum);


}