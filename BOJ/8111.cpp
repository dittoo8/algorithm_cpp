#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 20000 + 1;
int N;
pair<int, char> arr[MAX];
bool visited[MAX];
void BFS(){
    queue<int> q;
    //1부터 시작
    q.push(1);
    visited[1] = true;
    arr[1].first = -1;
    arr[1].second = '1';
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        int p[2];
        //10을 곱하면 0 추가
        //10 곱하고 1 더해주면 1 추가
        p[0] = (temp * 10) % N;
        p[1] = (p[0] + 1) % N;
        for (int i = 0; i < 2; i++) {
            if (!visited[p[i]]) {
                arr[p[i]].first = temp;
                arr[p[i]].second = i + '0';
                //N으로 나누어 떨어지면
                if (!p[i]) return;
                visited[p[i]] = true;
                q.push(p[i]);
            }
        }
    }
}
//역순으로 출력
void printPath(int num) {
    //기저 사례: 1까지 도달
    if (num == -1) return;
    printPath(arr[num].first);
    cout << arr[num].second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    for(int t=0; t<test_case; t++){
        cin >> N;
        //1인 경우 1 바로 출력
        if (N == 1){
            cout << 1 << "\n";
            continue;
        }
        memset(visited, false, sizeof(visited));
        BFS();
        printPath(0);
        cout << "\n";
    }
    return 0;
}