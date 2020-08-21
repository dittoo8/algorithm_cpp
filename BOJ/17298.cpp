#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	cin.tie(NULL); cout.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++){
        cin >> v[i];
    }
	stack<int> st;
	vector<int> ans(v.size(), -1);
	for (int i = 0; i < v.size(); i++) {
		while (!st.empty() && v[st.top()] < v[i]) {
			ans[st.top()] = v[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}