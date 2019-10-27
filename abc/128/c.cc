#include <iostream>
#include <vector>
using namespace std;

bitset<10> next(bitset<10> &s) {
	int d = 0;
	while(s[d]) s[d] = false, d++;
	s[d] = true;
	return s;
}


int main() {
	int N, M;
	cin >> N >> M;
	vector<bitset<10> > s(M);
	for(int i = 0; i < M; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int t;
			cin >> t;
			s[i][t-1] = true;
		}
	}

	vector<int> p(M);
	for(auto &x: p) cin >> x;

	int res = 0;
	for(bitset<10> sw; sw.to_ulong() < (1UL << N); sw = next(sw)) {
		for(int i = 0; i < M; i++) {
			bitset<10> t = sw & s[i];
			if(t.count() % 2 != p[i]) goto nextset;
		}
		res++;
		nextset:
		;
	}

	cout << res << endl;
}
