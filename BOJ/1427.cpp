#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
	return a > b;
}
int main(){
	int n;
    scanf("%d", &n);
	vector<int> v;
	int i = 0;
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i){
        printf("%d",v[i]);
    }
	return 0;
}