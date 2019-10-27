#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int N;
	long W;
	cin >> N >> W;
	const int V = N * 1000;
	vector<vector<long> > dp(N, vector<long>(V + 1, LONG_MAX));
	vector<pair<long, int> > a(N);
	for(auto& x: a) cin >> x.first >> x.second;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= V; j++) {
			if(j == 0) {
				dp[i][j] = 0;
			 }else if(i == 0) {
				if(j <= a[i].second) dp[i][j] = a[i].first;
			}
			else {
				if(dp[i - 1][j - a[i].second] != LONG_MAX) {
					dp[i][j] = min(dp[i - 1][j], a[i].first + dp[i - 1][j - a[i].second]);
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	int res = 0;
	for(int j = 0; j <= V; j++) {
		if(dp[N - 1][j] <= W)  {
			res = j;
		}
	}
	cout << res << endl;
	return 0;
}
