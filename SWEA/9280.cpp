#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n,m;
int r[101],w[10001];
vector<int> park;
queue<int> waiting;
queue<int> line;
int findMyPark(int x){
    for(int i=0;i<park.size();i++){
        if (x==park[i]){
            park[i]=0;
            return i;
        }
    }
    return 0;
}
int findPark(){
    for(int i=0;i<park.size();i++){
        if(!park[i]) return i;
    }
    return -1;
}
int solution(){
    int answer =0;
    while(!line.empty()|| !waiting.empty()){
        int now;
        if (!line.empty()){
            now = line.front();
            line.pop();
        } else {
            now = waiting.front();
            waiting.pop();
        }
        if(now > 0){
            //들어오는 차
            int idx =findPark();
            if(idx==-1) waiting.push(now);
            else {
                park[idx]=now;
                answer+=r[idx] * w[now-1];
            }
        } else {
            //나가는 차
            now*=-1;
            int idx = findMyPark(now);
            if(!waiting.empty()){
                //대기목록이 있다면
                park[idx]=waiting.front();
                answer+= r[idx]*w[waiting.front()-1];
                waiting.pop();
            }
        }
    }
    return answer;
}
int main(){
    int tc;
    scanf("%d", &tc);
    for(int t=1;t<=tc;t++){
        scanf("%d %d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%d", &r[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d", &w[i]);
        }
        for(int i=0;i<2*m;i++){
            int tmp;
            scanf("%d",&tmp);
            line.push(tmp);
        }
        park.resize(n);
        printf("#%d %d\n", t, solution());
    }
    return 0;
}