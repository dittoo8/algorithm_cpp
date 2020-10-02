#include <iostream>
using namespace std;
int n;
bool func(int num) {
	while (num >= 666) {
		if (num % 1000 == 666) return true;
		num /= 10;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	int i = 666;
	int cnt = 1;
	while (cnt<n) {
		i++;
		if (func(i)) cnt++;
	}
	cout << i << '\n';
	return 0;
}