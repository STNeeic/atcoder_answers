#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

int N;
	cin >> N;
	vector<int> h(N);
	for(auto &x: h) cin >> x;

	vector<int> a(N - 1);
	a[0] = abs(h[0] - h[1]);
	a[1] = min(abs(h[0] - h[2]), a[0] + abs(h[1] - h[2]));
	for(int i = 2; i < N - 1; i++) {
		a[i] = min(a[i - 1] + abs(h[i] - h[i + 1]), a[i - 2] + abs(h[i - 1] - h[i + 1]));
	}
	cout << a[N-2] << endl;
}
