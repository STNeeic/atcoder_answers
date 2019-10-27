#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

int N, K;
	cin >> N >> K;
	vector<int> h(N);
	for(auto &x: h) cin >> x;

	vector<int> a(N);
	a[0] = 0;
	for(int i = 1; i < N; i++) {
		int l = min(K, i);
		vector<int> b(l);
		for(int j = 0; j < l; j++) {
			b[j] = a[i - j - 1] + abs(h[i] - h[i - j - 1]);
		}
		a[i] = *min_element(b.begin(), b.end());
	}

	cout << a[N-1] << endl;
}
