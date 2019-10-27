#include <iostream>
#include <vector>

using namespace std;
const int M = 1000000007;

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char> > a(H, vector<char>(W));
	for(auto &x: a) {
		for(auto &c: x) cin >> c;
	}

	vector<vector<int> > dp(H, vector<int>(W, 0));

	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			if(i == 0 && j == 0) {
				dp[i][j] = 1;
				continue;
			}
			if(a[i][j] == '#') {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = 0;
			if(i > 0 && a[i-1][j] == '.') {
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= M;
			}
			if(j > 0 && a[i][j-1] == '.') {
				dp[i][j] += dp[i][j-1];
				dp[i][j] %= M;
			}
		}
	}

	cout << dp[H-1][W-1] << endl;
	return 0;
}
