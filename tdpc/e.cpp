#include <iostream>
#include <vector>
#include <string>
using namespace std;

const unsigned int c = 1000000007;

unsigned int dp[2][10000][100] = {};
int main() {
	int D;
	string N;
	cin >> D >> N;
	for(int i = 0; i < N[0] - '0'; i++) {
		dp[0][0][i] += 1;
	}
		dp[1][0][N[0] - '0'] += 1;

	for(int i = 1; i < N.size(); i++) {
		for(int j = 0; j < D; j++) {
			for(int k = 0; k < 10; k++) {
				dp[0][i][(j + k) % D] += dp[0][i - 1][j];
				dp[0][i][(j + k) % D] %= c;
				if(k < N[i] - '0') {
					dp[0][i][(j + k) % D] += dp[1][i - 1][j];
					dp[0][i][(j + k) % D] %= c;
				} else if(k == N[i] - '0') {
					dp[1][i][(j + k) % D] += dp[1][i - 1][j];
					dp[1][i][(j + k) % D] %= c;
				}
			}
		}
	}

	cout << (dp[0][N.size() - 1][0] + dp[1][N.size() - 1][0] - 1) % c << endl;
}
