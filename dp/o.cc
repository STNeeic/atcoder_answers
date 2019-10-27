#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
#include <bitset>
#include <unordered_map>

using namespace std;



unordered_map<bitset<21>, int> memo;

const int M = 1000000007;
int dfs(const vector<vector<int> > &m, int i, bitset<21> &s) {
	auto it = memo.find(s);
	if(it != memo.end()) return it->second;
	int N = m.size();
	if(s.count() == N) return 1;

	int out = 0;
	for(int j = 0; j < N; j++) {
		if(s[j] == false && m[i][j] == 1) {
			auto z = s;
			z[j] = true;
			out += dfs(m, i + 1, z);
			out %= M;
		}
	}
	memo.emplace(s, out);
	return out;
}

int main() {
	int N;
	cin >> N;
	vector<vector<int> > m(N, vector<int>(N));

	for(auto &r: m)
		for(auto &x: r) cin >> x;
	bitset<21> s;
	cout << dfs(m, 0, s) << endl;
}
