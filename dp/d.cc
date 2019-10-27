#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<vector<long> > dp(N, vector<long>(W + 1, 0));
	vector<pair<int, int> > a(N);
	for(auto& x: a) cin >> x.first >> x.second;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= W; j++) {
			if(i == 0) dp[i][j] = j - a[i].first >= 0 ? a[i].second : 0;
			else dp[i][j] = j - a[i].first < 0 ? dp[i-1][j] : max(dp[i - 1][j], a[i].second + dp[i - 1][j - a[i].first]);
		}
	}

	cout << dp[N - 1][W] << endl;
	return 0;
}
