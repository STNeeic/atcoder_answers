#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for(auto &x: a) cin >> x;

	vector<bool> b(N);

	int M = 0;
	for(int i = N; i >= 1; i--) {
		bool t = (a[i-1] == 1);
		for(int j = i * 2; j <= N; j += i) {
			if(b[j-1]) t = !t;
		}
		b[i-1] = t;
		if(t) M++;
	}

	cout << M << endl;
	for(int i = 0; i < N; i++) {
		if(b[i]) cout << i+1 << endl;
	}
}
