#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    int ret = 987654321;
    sort(dist.begin(),dist.end());
    do {
        vector<int> newWeak = weak;
        for(int j=0;j<weak.size();j++){
            if (j>0){
                newWeak.push_back(newWeak[0]+n);
                newWeak.erase(newWeak.begin());
            }
            int idx = 0;
            int cur = newWeak[0]+dist[idx];
            bool flag = false;
            for(int i=1;i<newWeak.size();i++){
                if(newWeak[i]>cur){
                    if(idx+1 == dist.size()){
                        flag= true;
                        break;
                    }
                    cur = newWeak[i]+dist[++idx];
                }
            }
            if(!flag) ret = min(ret,idx+1);
        }
    }while(next_permutation(dist.begin(),dist.end()));
    if (ret == 987654321) return -1;
    else return ret;
}
int main(){
    vector<int> v1 = {1,5,6,10};
    vector<int> v2 = {1,2,3,4};
    cout << solution(12,v1,v2) <<endl;
    return 0;
}