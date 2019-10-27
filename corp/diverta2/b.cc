#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

bool is_all(vector<bool> &b) {
	for(auto x: b) {
		if(x == false) return false;
	}
	return true;
}

int calc(vector<pair<int, int>> &p, pair<int, int> &c) {

	vector<bool> s(p.size(), false);

	int res = 1;
	s[0] = true;
	int bef = 0;
	while(is_all(s) == false) {
		for(int i = 0; i < p.size(); i++) {
			if(bef == i) continue;
			if(p[i].first - p[bef].first == c.first && p[i].second - p[bef].second == c.second) {
			s[i] = true;
			bef = i;
			goto next_calc;
			}
		}
		for(int i = 0; i < p.size(); i++) {
			if(s[i] == false) {
				res++;
				s[i] = true;
				bef = i;
				break;
			}
		}
		next_calc:
		;
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int> > p(N);
	for(auto &x: p) cin >> x.first >> x.second;

	sort(p.begin(), p.end());


	int out = N;
	for(int i = 0; i < N - 1; i++) {
		for(int j = i + 1; j < N; j++) {
			pair<int, int> c = make_pair(p[j].first - p[i].first, p[j].second - p[i].second);
			out = min(out, calc(p, c));
		}
	}

	cout << out << endl;
}
