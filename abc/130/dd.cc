#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N ;
	ll K;
	cin >> N >> K;
	vector<int> A(N);
	vector<ll> S(N, 0);
	vector<ll> RS(N, 0);
	for(int i = 0; i < N; i++) {
		 cin >> A[i];
		S[i] = i == 0 ? A[i] : A[i] + S[i - 1];
	}

	for(int i = N - 1; i >= 0; i--) {
		RS[i] = i == N - 1 ? A[i] : A[i] + RS[i + 1];
	}

	ll res = 0;
	for(int i = 0; i < N; i++) {
		ll s = S[N - 1];
		if(i > 0) s -= S[i - 1];
		if(s < K) break;
		int j;
		for(j = i; j < N; j++) {
			ll ss = s;
			if(j < N - 1) ss -= RS[j + 1];
			if(ss >= K) break;
		}
		cout << i << " " << j << endl;
		res += N - j;
	}

	cout << res << endl;
}

