#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    n-=2;
    n/=2;
    vector<int> bottom(n,-1);
    vector<int> holeIdx;
    vector<int> top(n,0);
    vector<int> width(n,0);
    map<int, int> dict;
    int x,y;
    cin >> x >> y; // (0,0)
    for(int i=0;i<n;i++){  // 수족관 경계
        int x1,y1,x2,y2; // y1 == y2 짝으로 입력받음
        cin >> x1 >> y1 >> x2 >> y2;
        bottom[i]=y1;
        width[i]=(x2-x1);
        dict[x2]=i; // 구역 번호 = i
    }
    cin >> x >> y; // (x,0)
    
    int m;
    cin >> m;
    for(int i=0;i<m;i++){ // 구멍 위치
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int index = dict[x2];
        holeIdx.push_back(index);
    }

    for(int i=0;i<holeIdx.size();i++){
        int idx = holeIdx[i];
        int surface =  bottom[idx];
        for(int j=idx;j>=0;j--){
            surface = min(surface, bottom[j]);
            //높이 갱신
            top[j] = max(top[j],surface);
        }
        surface =  bottom[idx];
        for(int j=idx+1;j<n;j++){
            surface = min(surface, bottom[j]);
            //높이 갱신
            top[j] = max(top[j],surface);
        }
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        if (bottom[i] > top[i]){
            ans += (long long)(bottom[i]-top[i])*width[i];
        }
    }
    cout << ans << '\n';
    return 0;
}