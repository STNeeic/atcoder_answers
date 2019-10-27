#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[400][400] = {};
long long rec(const vector<int> &a, const vector<long long> &s, int l, int r) {
	if(dp[l][r] != 0) return dp[l][r];
	if(l == r) return 0;
	if(l + 1 == r) return dp[l][r] = a[l] + a[r];

	long long res = LLONG_MAX;
	for(int k = l; k < r; k++) {
		long long ss = rec(a, s, l, k) + rec(a, s, k + 1, r);
		res = min(ss, res);
	}
	dp[l][r] = l > 0 ? res + s[r] - s[l - 1] : res + s[r];
	//cout << l << " " << r << " " << dp[l][r] << endl;
	return dp[l][r];
}
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<long long> s(N);
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		s[i] = i == 0 ? a[i] : a[i] + s[i - 1];
	}

	cout << rec(a, s, 0, N - 1) << endl;

}
