#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int gcd(int a, int b) {
	if(a == 0) return b;
	if(b == 0) return a;
	if(a > b) swap(a, b);
	int r = b % a;
	if(r == 0) return a;
	else return gcd(r, a);
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &x: A) cin >> x;
	vector<int> L(N+1, 0), R(N+1, 0);
	for(int i = 0; i < N; i++) {
		L[i + 1] = gcd(L[i], A[i]);
	}
	for(int i = N - 1; i >= 0; i--) {
		R[i] = gcd(R[i + 1], A[i]);
	}
	int res = 0;
	for(int i = 0; i < N; i++) {
		int m = gcd(L[i], R[i + 1]);
		res = max(res, m);
	}
	cout << res << endl;
}
