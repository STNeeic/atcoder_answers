#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main () {

	int N;
	cin >> N;

	vector<long> a(N);
	for(auto &x: a) cin >> x;

	vector<vector<long> > dp(N + 1, vector<long>(N + 1, 0));

	for(int i = N - 1; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			if(i % 2 == 0) {
				dp[i - j][j] = max(dp[i - j + 1][j] + a[i - j], dp[i - j][j + 1] + a[N - j - 1]);
			} else {
				dp[i - j][j] = min(dp[i - j + 1][j] - a[i - j], dp[i - j][j + 1] - a[N - j - 1]);
			}
		}
	}

	cout << dp[0][0] << endl;
}
