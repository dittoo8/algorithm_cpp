#include <iostream>
#include <queue>
using namespace std;
int main(){
    int prior[101];
    queue<int> q;
    priority_queue<int> pq;
    int tc;
    cin >> tc;
    while(tc--){
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            prior[i]=tmp;
            q.push(i);
            pq.push(tmp);
        }
        int cnt = 1;
        while(true){
            if(prior[q.front()] == pq.top()){
                // 가장 앞에 있는 문서의 중요도가 제일 높은 경우
                if(q.front()==m){
                    // 문서가 m일 경우, count 출력
                    cout << cnt << '\n';
                    break;
                }else {
                    // 다른 문서일 경우 pop 하고 count++
                    cnt++;
                    q.pop();
                    pq.pop();
                }
            }else {
                // 가장 앞 문서의 중요도가 제일 높지않은 경우 queue의 가장 뒤로 재배치
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}