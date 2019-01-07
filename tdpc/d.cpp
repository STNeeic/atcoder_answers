#include <iostream>

using namespace std;
double dp[201][101][101] = {};

int main() {
	dp[0][0][0] = 1.0/6.0;
	dp[1][0][0] = 1.0/6.0;
	dp[0][1][0] = 1.0/6.0;
	dp[2][0][0] = 1.0/6.0;
	dp[0][0][1] = 1.0/6.0;
	dp[1][1][0] = 1.0/6.0;

	int N;
	unsigned long long D;
	int a, b, c;
	double res = 0;
	cin >> N >> D;

	for(a = 0; D % 2 == 0;D /= 2)a++;
	for(b = 0; D % 3 == 0;D /= 3)b++;
	for(c = 0; D % 5 == 0;D /= 5)c++;
	//cout << a << " " << b << " " << c << endl;
	if(D > 1) {
		cout << "0" << endl;
		return 0;
	}

	if(N == 1) {
		cout << dp[a][b][c] << endl;
		return 0;
	}
	for(int i = 1; i < N; i++) {
		for(int x = 2 * N; x >= 0; x--) {
		for(int y = N; y >= 0; y--) {
		for(int z = N; z >= 0; z--) {
			double sum = 1.0/6.0 * dp[x][y][z];
			if(x > 0) sum += 1.0/6.0 * dp[x - 1][y][z];
			if(y > 0) sum += 1.0/6.0 * dp[x][y - 1][z];
			if(x - 1> 0) sum += 1.0/6.0 * dp[x - 2][y][z];
			if(z > 0) sum += 1.0/6.0 * dp[x][y][z - 1];
			if(x > 0 && y > 0) sum += 1.0/6.0 * dp[x - 1][y - 1][z];
			dp[x][y][z] = sum;
			//cout << sum << " ";
			if(i + 1 == N && x >= a && y >= b && z >= c) res += sum;
		}
		}
		}
		//cout << endl;
	}

	cout << res << endl;
}
