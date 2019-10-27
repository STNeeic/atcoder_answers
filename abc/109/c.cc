#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
unsigned int gcd(unsigned int a, unsigned int b) {
	if(a == 0) return b;
	if(b == 0) return a;
	if(a > b) swap(a, b);
	int r = b % a;
	return gcd(r, a);
}

int main() {
	int N, X;
	cin >> N >> X;
	unsigned int res = 0;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		res = gcd(res, abs(X - x));
	}

	cout << res << endl;
}
