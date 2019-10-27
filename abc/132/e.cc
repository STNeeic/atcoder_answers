#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
int main() {
	int N, M;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	vector<vector<int> > V(3 * N + 1);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		V[u].push_back(v + N);
		V[u + N].push_back(v + 2 * N);
		V[u + 2 * N].push_back(v);
	}

	vector<int> s(3 * N + 1, -1);

	int S, T;
	cin >> S >> T;
	s[S] = 0;

	queue<int> q;
	q.push(S);
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		for(auto x: V[p]) {
			if(s[x] >= 0) continue;
			s[x] = s[p] + 1;
			if(x == T) {
				cout << s[x] / 3<< endl;
				return 0;
			}
			q.push(x);
		}
	}
	cout << -1 << endl;
}
