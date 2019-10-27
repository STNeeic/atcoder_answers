#include <iostream>
#include <vector>
using namespace std;

int main() {
int N;
	cin >> N;
	vector<int> A(N);
	for(auto &x: A) cin >> x;

	long long s = 0;
	for(auto x: A) s += x;

	long long a = s;
	for(int i = 1; i < N; i+=2) a -= 2 * A[i];
	cout << a << " ";
	for(int i = 0; i < N - 1; i++, cout << " ") {
		long long b = 2 * A[i] - a;
		cout << b;
		a = b;
	}
	cout << endl;
}
