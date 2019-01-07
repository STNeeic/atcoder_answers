#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<vector<int> > dp(N, vector<int>(W + 1, 0));
	vector<pair<int, int> > item(N);

	for(auto & x:item) {
		cin >> x.first >> x.second;
	}

	for(int i = 0; i < dp.size(); i++) {
		for(int j = 0; j < dp[i].size(); j++) {
			if(j + item[i].first > W) {
				dp[i][j] = i > 0 ? dp[i - 1][j] : 0;
			} else if(i == 0) {
				dp[i][j] = item[i].second;
			} else {
				dp[i][j] = max(dp[i - 1][j + item[i].first] + item[i].second, dp[i - 1][j]);
			}
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << dp[N - 1][0] << endl;
}
