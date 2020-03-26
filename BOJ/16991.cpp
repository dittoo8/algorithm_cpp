#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 99999999.999999
pair<int,int> arr[16];
double cost[16][16];
double dp[16][1 << 16];
int N;
double TSP(int start, int visit) {
    if (visit == ((1 << N) - 1)) {
        if (cost[start][0] == 0) return MAX;
        else return cost[start][0];
    }
    double& result = dp[start][visit];
    if (result) return result;
    double len = MAX;
    for (int i = 1; i < N; i++) {
        if (cost[start][i] != 0 && (visit & (1 << i)) == 0) {
            len = min(len, cost[start][i] + TSP(i, visit | (1 << i)));
        }
    }
    return result = len;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    for (int i = 0; i < N; i++) {
        int fx = arr[i].first, fy = arr[i].second;
        for (int k = i + 1; k < N; k++) {
            int lx = arr[k].first, ly = arr[k].second;
            cost[i][k] = cost[k][i] = sqrt(pow(lx - fx, 2) + pow(ly - fy, 2));
        }
    }
    printf("%.9f", TSP(0, 1));
    return 0;
}