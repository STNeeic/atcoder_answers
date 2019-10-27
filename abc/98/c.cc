#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	int N;
	string S;
	cin >> N >> S;
	vector<int> E(N, 0), W(N, 0);

	for(int i = 0; i < N; i++) {
		int b = i == 0 ? 0 : W[i - 1];
		W[i] = S[i] == 'W' ? b + 1 : b;
		b = i == 0 ? 0 : E[N - i];
		E[N - i - 1] = S[N - i - 1] == 'E' ? b + 1 : b;
	}

	int m = INT_MAX;
	for(int i = 0; i < N; i++) {
		int n = W[i] + E[i];
		if(W[i] > 0 && S[i] == 'W') n--;
		else if(E[i] > 0 && S[i] == 'E') n--;

		m = min(m, n);
	}
	cout << m << endl;
}
