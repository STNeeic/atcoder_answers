#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool check_flg(vector<bool> &flag, vector<pair<vector<int>, vector<int> > > &na, int i) {
	for(int j = 0; j < na[i].second.size(); j++) {
		if(flag[na[i].second[j]] == false) return false;
	}
	return true;
}
int main() {
	int N, M;
	cin >> N >> M;

	vector<pair<vector<int>, vector<int> > > na(N);
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		na[a-1].first.push_back(b-1);
		na[b-1].second.push_back(a-1);
	}

	vector<int> n;
	//topological sort

	vector<bool> flag(N, false);
	deque<int> dp;
	for(int i = 0; i < N; i++) {
		if(na[i].second.size() == 0) {
			n.push_back(i);
			dp.push_back(i);
			flag[i] = true;
		}
	}

	while(dp.size() > 0) {
		int nn = dp.back();
		dp.pop_back();
		if(check_flg(flag, na, nn) == false) continue;
		if(flag[nn] == false) {
			n.push_back(nn);
			flag[nn] = true;
		}
		for(int i = 0; i < na[nn].first.size(); i++) {
			if(flag[na[nn].first[i]] == false)
				dp.push_back(na[nn].first[i]);
		}
	}

	//for(auto x: n) cout << x << " ";
	//cout << endl;

	vector<int> dd(N, 0);
	int out = 0;
	for(int i = 1; i < N; i++) {
		int nm = 0;
		for(int j = 0; j < na[n[i]].second.size(); j++) {
			nm = max(nm, dd[na[n[i]].second[j]] + 1);
	//		cout << na[n[i]].second[j] <<  "->" << n[i] << " " << nm << endl;
		}
		dd[n[i]] = nm;
		out = max(out, dd[n[i]]);
	}
	cout << out << endl;
	return 0;
}
