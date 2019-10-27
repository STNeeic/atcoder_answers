#include <iostream>
#include <vector>

using namespace std;

int calc(vector<int> n, const vector<int> &P, const vector<int> &C, const int G, const int h=0) {
	if(h >= G) {
		int out = 0;
		for(auto x: n) out += x;
		return out;
	}
	int D = n.size();
	int res = INT_MAX;
	for(int i = 0; i < D; i++) {
		if(n[i] == P[i]) continue;
		if(P[i] * 100 * (i + 1) + C[i] + h > G) {
			int j = 0;
			for(; j < P[i]; j++) {
				if(j * 100 * (i + 1) + h >= G) break;
			}
			n[i] = j;
		} else {
			n[i] = P[i];
		}
		int hh = n[i] * 100 * (i + 1);
		if(n[i] == P[i]) hh += C[i];
		res = min(res, calc(n, P, C, G, h + hh));
		n[i] = 0;
	}
	return res;
}
int main() {
	int D, G;
	cin >> D >> G;

	vector<int> C(D);
	vector<int> P(D);

	for(int i = 0; i < D; i++) {
		cin >> P[i] >> C[i];
	}
	auto n = vector<int>(D, 0);
	cout << calc(n, P, C, G) << endl;
}
