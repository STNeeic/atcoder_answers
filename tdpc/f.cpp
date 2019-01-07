#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const long M = 1000000007;
int main(void) {
	int N, K;
	cin >> N >> K;
	vector<pair<long, long> > sum(N);
	long s = 0;
	sum[0] = make_pair(0, 1);
	for(int i = 1; i < N ; i++) {
		sum[i].first = sum[i - 1].first + sum[i - 1].second;
		sum[i].first %= M;
		if(i < K - 1) {
			sum[i].second = sum[i].first;
		} else {
			sum[i].second += s;
			/*if(i == K - 1) {
				sum[i].second += sum[1].second;
			}*/
			sum[i].second %= M;
		}
		s += sum[i].first;
		if(i >= K - 1) s += M - sum[i - (K - 1)].first;
		s %= M;
	}

	//for(auto x: sum) cout << x.first << " " << x.second << endl;
	cout << sum[N - 1].second << endl;
	return 0;
}
