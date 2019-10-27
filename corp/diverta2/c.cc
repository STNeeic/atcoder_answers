#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &x: A) cin >> x;

	sort(A.begin(), A.end());

	long long M = 0;
	for(int i = 0; i < N ; i++) {
		if(i == 0) M -= A[i];
		else if(i == N - 1) M += A[i];
		else if(A[i] < 0) M -= A[i];
		else M += A[i];
	}
	cout << M << endl;
	int P = 1, Q = 1;
	for(int i = 1; i < N - 1; i++) {
		if(A[i] < 0) P++;
		else Q++;
	}

	long long a = A[0], b = A[N - 1];

	while(Q > 1) {
		cout << a << " " << A[N - Q] << endl;
		a -= A[N - Q];
		Q--;
	}

	while(P > 1) {
		cout << b << " " << A[P - 1] << endl;
		b -= A[P - 1];
		P--;
	}

	cout << b << " " << a << endl;
}
