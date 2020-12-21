#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b, c, result, mx;
    cin >> a >> b >> c;
	if (a == b && a == c){
        result = 10000 + a * 1000;
    }else if (a == b || a == c){
        result = 1000 + a * 100;
    }else if (b == c){
        result = 1000 + b * 100;
    }else {
		mx = max(a, b);
		mx = max(mx, c);
		result = mx * 100;
	}
    cout << result << '\n';
	return 0;
}