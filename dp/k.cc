#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> a(N);
	for(auto &x: a) cin >> x;
	vector<pair<bool, bool> > dp(K+1);

	for(int i = 0; i <= K; i++) {
		pair<bool, bool> flg = make_pair(false, false);
		for(auto x: a) {
			if(i - x >= 0) {
				if(dp[i - x].first == false) {
					flg.second = true;
				}
				if(dp[i - x].second == false) {
					flg.first = true;
				}
			}
		}
		dp[i] = flg;
	}

/*
	for(auto x: dp) {
		cout << "(";
		cout << (x.first ? "t" : "f");
		cout << ",";
		cout << (x.second ? "t" : "f") << ")";
	}
	cout << endl;
*/
	if(dp[K].first) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}
}
