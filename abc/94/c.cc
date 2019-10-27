#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> X(N);
	vector<int> Y(N);

	for(int i = 0; i < N; i++) {
		cin >> X[i];
		Y[i] = X[i];
	}

	sort(Y.begin(), Y.end());

	int medl = Y[N/2 - 1];
	int medr = Y[N/2];

	for(auto x: X) {
		if(x <= medl) cout << medr << endl;
		else cout << medl << endl;
	}

	return 0;
}
