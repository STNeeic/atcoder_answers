#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> X(N);
	for(auto &x: X) cin >> x;

	int res = INT_MAX;
	for(int i = 0; i < N - K + 1; i++) {
		int l = X[i];
		int r = X[i + K - 1];

		int llen = abs(l) + abs(l - r);
		int rlen = abs(r) + abs(l - r);
		res = min({res, llen, rlen});
	}

	cout << res << endl;
}
