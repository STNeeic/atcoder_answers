#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector< tuple<int, int, int> > h(N);
	vector< tuple<int, int, int> > dp(N + 1);

	for(auto &x: h) {
		int a, b, c;
		cin >> a >> b >> c;
		x = make_tuple(a, b, c);
	}

	dp[0] = make_tuple(0,0,0);

	for(int i = 1; i <= N; i++) {
		int a[3];
			a[0] = max(get<1>(dp[i-1]) + get<0>(h[i-1]), get<2>(dp[i-1]) + get<0>(h[i-1]));
			a[1] = max(get<2>(dp[i-1]) + get<1>(h[i-1]), get<0>(dp[i-1]) + get<1>(h[i-1]));
			a[2] = max(get<0>(dp[i-1]) + get<2>(h[i-1]), get<1>(dp[i-1]) + get<2>(h[i-1]));
		dp[i] = make_tuple(a[0], a[1], a[2]);
	}

	cout << max({get<0>(dp[N]), get<1>(dp[N]), get<2>(dp[N])}) << endl;
}
