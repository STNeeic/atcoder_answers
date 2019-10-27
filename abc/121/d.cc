#include <iostream>
#include <cmath>
using namespace std;


int main() {
	long long A, B;
	cin >> A >> B;
	A--;
	long long O = 0;

	for(int i = 0; (1LL << i) <= B; i++) {
		long long m = 1LL << (i + 1);
		m--;
		long long a = A & m, b = B & m;
		long long sum = 0;
		if(a < b) {
			sum += max(0LL, b - (1LL << i) + 1);
			sum -= max(0LL, a - (1LL << i) + 1);
		} else if(a > b) {
			sum += min(1LL << i, (1LL << (i + 1)) - a);
			sum += max(0LL, b - (1LL << i) + 1);
		}
		cout << i << " " << sum << endl;
		long long k = sum % 2 == 0 ? 0 : 1;
		O |= k << i;
	}
	cout << O << endl;
}
