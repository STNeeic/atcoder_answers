#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N - 1);
	for(auto &x: A) cin >> x;
	for(auto &x: B) cin >> x;
	for(auto &x: C) cin >> x;

	int sum = 0;
	for(int i = 0, prev = INT_MAX; i < N; i++) {
		int j = A[i] - 1;
		sum += B[j];
		if(prev == j - 1) sum += C[prev];
		prev = j;
	}

	cout << sum << endl;
}
