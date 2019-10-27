#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 1000000007;
int main() {
	long long N, K;
	cin >> N >> K;

	vector<int> a(N);
	for(auto &x: a) cin >> x;

	vector<vector<int> > dp(N, vector<int>(K + 1, 0));

	long long m = 0;
	for(int i = 0; i < N; i++) {
		m += a[i];
		int acc = 0;
		for(int j = 0;j <= min(K, m); j++) {
			if(i == 0) {
				dp[i][j] = 1;
				continue;
			}
			acc += dp[i-1][j];
			acc %= M;
			if(j > a[i]) {
				acc += M - dp[i-1][j - a[i] - 1];
				acc %= M;
			}
			dp[i][j] = acc;
		}
	}

	cout << dp[N - 1][K] << endl;
	return 0;
}
