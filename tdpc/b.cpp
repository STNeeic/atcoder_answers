#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int DOWN_CLOSE = 1;
const int RIGHT_CLOSE = 2;

int c[2][1001] = {};

pair<int, int> dp[1001][1001] = {};

int main() {
	int A, B;
	cin >> A >> B;
	for(int i = 0; i < A; i++) cin >> c[0][i];
	for(int i = 0; i < B; i++) cin >> c[1][i];

	for(int i = 0; i <= A; i++) dp[i][B].first |= RIGHT_CLOSE;
	for(int i = 0; i <= B; i++) dp[A][i].first |= DOWN_CLOSE;

	for(int i = A; i >= 0; i--) {
		for(int j = B; j >= 0; j--) {
			int l = c[0][i], r = c[1][j];
			if(i == A && j == B) continue;

			if((dp[i][j].first & RIGHT_CLOSE) == 0) {
				if((dp[i][j + 1].first & RIGHT_CLOSE) == 0) {
					r += dp[i][j + 2].second;
				} else if((dp[i][j + 1].first & DOWN_CLOSE) == 0) {
					r += dp[i + 1][j + 1].second;
				}
			}
			if((dp[i][j].first & DOWN_CLOSE) == 0) {
				if((dp[i + 1][j].first & RIGHT_CLOSE) == 0) {
					l += dp[i + 1][j + 1].second;
				} else if((dp[i + 1][j].first & DOWN_CLOSE) == 0) {
					l += dp[i + 2][j].second;
				}
			}
			if(l > r) {
				dp[i][j].first |= RIGHT_CLOSE;
				dp[i][j].second = l;
			} else {
				dp[i][j].first |= DOWN_CLOSE;
				dp[i][j].second = r;
			}
		}
	}
	cout << dp[0][0].second << endl;
}
