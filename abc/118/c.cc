#include <iostream>
#include <vector>
using namespace std;

int in_gcd(int a, int b) {
	return b != 0 ? in_gcd(b, a % b) : a;
}
int gcd(int a, int b) {
	return a > b ? in_gcd(a, b) : in_gcd(b, a);
}

int main() {

	int N;
	cin >> N;
	int A;
	cin >> A;
	for(int i = 1; i < N; i++) {
		int B;
		cin >> B;
		A = gcd(A, B);
	}

	cout << A << endl;
}
