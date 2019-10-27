#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int get_j(int i, vector<ll> &RS, ll s, ll K) {
	int N = RS.size();
	int len = N - i;
	int j = i + len / 2;
	while(len > 1) {
		ll ss = s;
		if(j < N - 1) ss -= RS[j + 1];
		if(ss == K) return j;
		int llen = (len + 1) / 2;
		if(ss < K) {
			j += llen / 2;
			if(len % 2 == 0 && (len / 2) % 2 == 1) j++;
		} else {
			j -= llen / 2;
			if(len % 2 == 1 && (len / 2) % 2 == 0) j--;
		}
		len /= 2;
	}
	return j;
}
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

	reverse(RS.begin(), RS.end());

	ll res = 0;
	for(int i = 0; i < N; i++) {
		ll s = S[N - 1];
		if(i > 0) s -= S[i - 1];
		if(s < K) break;
		ll ss = i == 0 ? 0 : S[i - 1];
		auto j = lower_bound(S.begin(), S.end(), K + ss);
		if(j == S.end()) continue;
		res += N - (j - S.begin());
	}

	cout << res << endl;
}
