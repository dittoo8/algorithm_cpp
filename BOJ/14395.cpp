#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
set<long long> visited;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	long long s, t;
	cin >> s >> t;
	if (s == t){
		cout << 0 << "\n";
		return 0;
	}
	queue<pair<long long, string> > q;
    q.push(make_pair(s,""));
    visited.insert(s);
	bool flag = true;
	while (!q.empty()){
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			long long x = q.front().first;
            string str = q.front().second;
			q.pop();
			if (x == t){
				cout << str << "\n";
				return 0;
			}
			long long temp = x*x;
			if (temp <= t && visited.find(temp)==visited.end()){
				q.push(make_pair(temp,str+'*'));
                visited.insert(temp);
			}
			temp = x*2;
			if (temp <= t &&visited.find(temp)==visited.end()){
				q.push(make_pair(temp,str+'+'));
                visited.insert(temp);
			}
			if (flag){
				q.push(make_pair(1,str+'/'));
				flag = false;
			}
		}
	}
	cout << -1 << "\n";
	return 0;
}