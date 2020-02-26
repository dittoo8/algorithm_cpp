#include <iostream>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};
int solution(vector<vector<int> > jobs) {
    int answer = 0, j = 0, time = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int> >, cmp> pq;
    while (j < jobs.size() || !pq.empty()) {
        if (jobs.size() > j && time >= jobs[j][0]) {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[j][0];
    }
    return answer / jobs.size();
}
int main(){
    vector<vector<int> > v;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(9);
    vector<int> v3;
    v3.push_back(2);
    v3.push_back(6);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout << solution(v) << endl;
    return 0;
}