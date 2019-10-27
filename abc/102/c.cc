#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> B(N);
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		B[i] = x - (i + 1);
	}
	sort(B.begin(), B.end());
	int b;
	if(N % 2 == 1) {
		b = B[(N - 1)/2];
	} else {
		b = (B[N / 2] + B[(N - 2) / 2]) / 2;
	}
	int res = 0;
	for(int i = 0; i < N; i++) {
		res += abs(B[i] - b);
	}
	cout << res << endl;
}
