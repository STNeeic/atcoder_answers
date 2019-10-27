#include <iostream>
#include <bitset>

using namespace std;

int main() {

	bitset<30> a;
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < M; i++) a[i] = true;

	for(int i = 0; i < N; i++) {
		bitset<30> b;
		int K;
		cin >> K;
		for(int j = 0; j < K; j++) {
			int l;
			cin >> l;
			b[l - 1] = true;
		}
		a &= b;
	}

	cout << a.count() << endl;
}
