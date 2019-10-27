#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &x: A) cin >> x;

	sort(A.begin(), A.end());

	int a = A[(N - 1) / 2], b = A[N / 2];
	cout << b - a << endl;
}
