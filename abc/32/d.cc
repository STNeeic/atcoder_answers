#include <iostream>
#include <vector>
#include <bitset>
#include <stack>

using namespace std;

void solve1(int N, int W, const vector<pair<int, int> > &A) {
 //総当たり
	stack<pair<int, pair<unsigned long long, int> > > st;
	unsigned long long sum = 0;
	st.push(make_pair(1,make_pair(0, 0)));
	if(A[0].second <= W) st.push(make_pair(1, A[0]));
	while(st.empty() != true) {
		auto x = st.top();
		st.pop();
		if(x.first == N) {
			sum = max(sum, x.second.first);
			continue;
		}
		int i = x.first;
		int w = x.second.second;
		auto v = x.second.first;
		if(w + A[i].second <= W) {
			st.push(make_pair(i + 1, make_pair(v + A[i].first, w + A[i].second)));
		}
			st.push(make_pair(i + 1, x.second));
	}

	cout << sum << endl;
}

void solve2(int N, int W, const vector<pair<int ,int> > &A) {
	// dp using w
	vector<vector<unsigned long long> > dp(N + 1, vector<unsigned long long>(W + 1, 0));

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= W; j++) {
			dp[i][j] = A[i-1].second <= j ? max(dp[i-1][j], dp[i-1][j-A[i-1].second] + A[i-1].first) : dp[i-1][j];
		}
	}

	cout << dp[N][W] << endl;
}

void solve3(int N, int W, const vector<pair<int , int> > &A) {
	//dp using v
	vector<vector<unsigned long long> > dp(N + 1, vector<unsigned long long>(1001, ULLONG_MAX / 3));
	dp[0][0] = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= 1000; j++) {
			dp[i][j] = A[i-1].first <= j ? min(dp[i-1][j], dp[i-1][j-A[i-1].first] + A[i-1].second) : dp[i-1][j];
		}
	}

	int v = 0;
	for(int i = 0; i <= 1000; i++) {
		if(dp[N][i] <= W) v = i;
	}
	cout << v << endl;
}

int main() {
	int N, W;
	cin >> N >> W;
	vector<pair<int, int> > A(N);
	for(auto &x: A) cin >> x.first >> x.second;

	if(N <= 30) solve1(N, W, A);
	else if(W <= 1000) solve2(N, W, A);
	else solve3(N, W, A);
}
