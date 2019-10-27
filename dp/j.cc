#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < N; i++) {
		int h;
		cin >> h;
		if(h == 3) a++;
		if(h == 2) b++;
		if(h == 1) c++;
	}

	vector<vector<vector<double> > > dp(N + 1, vector<vector<double> >(N + 1, vector<double>(N + 1, 0.0)));

	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N - i; j++) {
			for(int k = 0; k <= N - j - i; k++) {
				double h = i + j + k;
				double out = h > 0 ? N / h : 0;
				if(k > 0) out += k / h * dp[i][j][k - 1];
				if(j > 0) out += j / h * dp[i][j - 1][k + 1];
				if(i > 0) out += i / h * dp[i - 1][j + 1][k];
				dp[i][j][k] = out;
			}
		}
	}
	cout << fixed << setprecision(9) << dp[a][b][c] << endl;
}
