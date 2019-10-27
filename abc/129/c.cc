#include <iostream>
#include <vector>


using namespace std;

const int MOD = 1000000007;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> a(N + 1, 0);
	for(int i = 0; i < M; i++) {
		int x;
		cin >> x;
		a[x] = 1;
	}
	vector<int> ptn(N+1, 0);
	ptn[0] = 1;
	if(a[1] != 1) ptn[1] = 1;
	for(int i = 2; i <= N; i++) {
		if(a[i] == 1) continue;
		ptn[i] = ptn[i - 1] + ptn[i - 2];
		ptn[i] %= MOD;
	}

	cout << ptn[N] << endl;
}
