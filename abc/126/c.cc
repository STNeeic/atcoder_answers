#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> num(N + 1, 0);
	for(int i = 1; i <= N; i++) {
		int j = 0;
		for(;(i << j) < K; j++);
		num[i] = j;
	}
	vector<double> res(N + 1, 0.0);
	for(int i = 1; i <= N; i++) {
		res[i] = 1.0 / (double) N * pow(0.5, num[i]);
	}

	double out = 0;
	for(auto x: res) out += x;
	cout << fixed << setprecision(9) << out << endl;
}
