#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> W(N);
	for(auto &x: W) cin >> x.second >> x.first;
	sort(W.begin(), W.end());

	int t = 0;
	for(auto x: W) {
		t += x.second;
		if(t > x.first) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
