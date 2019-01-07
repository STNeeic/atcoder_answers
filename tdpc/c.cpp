#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double dp[1024][11] = {};
int R[1024];

double P(int a, int b) {
	//cout << "P" << " " << a << " " << b << endl;
	return 1.0 / (1.0 + pow(10.0,(double) (b - a) / 400.0));
}

int nblk(int i, int j) {
	int cell_size = 1 << j;
	int b = (i / cell_size) * cell_size;
	int pos = i - b < cell_size / 2 ? b + cell_size / 2 : b;
	//cout << cell_size << " " << b << " " << pos << " cell, b, pos" << endl;
	return pos - 1;
}

int main() {
	int K;
	cin >> K;
	int N = 1 << K;
	for(int i = 0; i < N; i++) cin >> R[i];
	for(int i = 0; i < N; i++) dp[i][0] = 1.0;

	for(int j = 1; j <= K; j++) {
		for(int i = 0; i < N; i++) {
			for(int k = 1; k <= 1 << (j - 1); k++) {
				//cout << i << ">" << nblk(i,j) + k<< " ";
				dp[i][j] += P(R[i], R[nblk(i, j) + k]) * dp[nblk(i, j) + k][j - 1];
			}
				dp[i][j] *= dp[i][j-1];
		}
	}
/*
	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= K; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
*/
	cout << fixed << setprecision(9);
	for(int i = 0; i < N; i++) cout << dp[i][K] << endl;
}
