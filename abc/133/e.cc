#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int> > T(N);

	for(int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		T[a-1].push_back(b-1);
		T[b-1].push_back(a-1);
	}

	stack<int> s;
	s.push(0);
	const ll M = 10e9 + 7;
	ll res = 0;

	vector<bool> t(N, false);
	while(!s.empty()) {
		int a = s.top();
		s.pop();
		if(a == 0) {
			res = K;
		}
		int c = T[a].size();
		if(a == 0) {
			for(int i = 1; i <= c; i++) {
				res *= K - i;
				res %= M;
				s.push(T[a][i-1]);
			}
		} else {
			for(int i = 0; i < c - 1; i++) {
				res *= K - i - 2;
				res %= M;
			}
			for(int i = 0; i < c; i++) {
				if(t[T[a][i]] == true) continue;
				else s.push(T[a][i]);
			}
		}
		t[a] = true;
	}
	cout << res << endl;
}
