#include <iostream>
#include <vector>

using namespace std;

int main() {
int N, K;
	cin >> N >> K;
	vector<int> V(N);
	for(auto &x: V) cin >> x;

	int rres = 0;
	for(int a = 0; a <= min(K, N); a++) {
		for(int b = 0; b + a <= min(K, N); b++) {
			vector<int> c(a + b);
			int res = 0;
			for(int i = 0; i < a; i++) {
				c[i] = V[i];
			}
			for(int j = 0; j < b; j++) {
				c[a + j] = V[N - 1 - j];
			}

			sort(c.begin(), c.end());
			int M = K - a - b;
			for(auto x: c) {
				if(x < 0 && M > 0) {
					M--;
				} else {
					res += x;
				}
			}
			rres = max(rres, res);
		}
	}

	cout << rres << endl;
}
