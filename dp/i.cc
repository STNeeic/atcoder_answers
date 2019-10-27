#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<double> p(N);
	for(auto& x: p) cin >> x;

	vector<double> a(N + 1, 0.0), b(N + 1, 0.0);
	a[0] = 1.0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j <= i + 1; j++) {
			if(j == 0) b[j] = (1.0 - p[i]) * a[j];
			else b[j] = p[i] * a[j - 1] + (1.0 - p[i]) * a[j];
		}
		for(int j = 0; j <= i + 1; j++) {
			a[j] = b[j];
		}
	}

	double out = 0.0;
	for(int i = N / 2 + 1;i <= N; i++) {
		out += a[i];
	}
	cout.precision(9);
	cout << out << endl;
}
