#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
int main() {
	int g1, s1, b1;
	int g2, s2, b2;
	int N;
	cin >> N;
	cin >> g1 >> s1 >> b1;
	cin >> g2 >> s2 >> b2;

	vector<ll> dp1(N + 1, 0);

	pair<int, int> v[4];

	v[0] = make_pair(g1, g2);
	v[1] = make_pair(s1, s2);
	v[2] = make_pair(b1, b2);
	v[3] = make_pair(1, 1); //買わない

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 4; j++) {
			if(i - v[j].first < 0) continue;
			dp1[i] = max(dp1[i], dp1[i - v[j].first] + v[j].second);
		}
	}

	ll M = dp1[N];

	vector<ll> dp2(M + 1, 0);
	pair<int, int> w[4];
	w[0] = make_pair(g2, g1);
	w[1] = make_pair(s2, s1);
	w[2] = make_pair(b2, b1);
	w[3] = make_pair(1, 1);

	for(ll i = 1; i <= M; i++) {
		for(int j = 0; j < 4; j++) {
			if(i - w[j].first < 0) continue;
			dp2[i] = max(dp2[i], dp2[i - w[j].first] + w[j].second);
		}
	}
	cout << dp2[M] << endl;
}
