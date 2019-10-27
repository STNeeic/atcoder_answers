#include <iostream>
using namespace std;

long long C[2001][2001] = {};
const long long M = 1e9 + 7;
int main() {
	for(int i = 0; i <= 2000; i++) {
		for(int j = 0; j <= i; j++) {
			if(j == 0) {
				C[i][j] = 1;
				continue;
			} else {
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				C[i][j] %= M;
			}
		}
	}

	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= K; i++) {
		long long a = C[N - K + 1][i];
		long long b = C[K - 1][i - 1];
		cout << (a * b) % M << endl;
	}
}
