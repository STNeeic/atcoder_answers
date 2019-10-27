#include <iostream>
#include <vector>
#include <functional>

using namespace std;
int main() {
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<long long> a(X), b(Y), c(Z);
	for(auto &x: a) cin >> x;
	for(auto &x: b) cin >> x;
	for(auto &x: c) cin >> x;

	sort(a.begin(), a.end(), greater<long long>());
	sort(b.begin(), b.end(), greater<long long>());
	sort(c.begin(), c.end(), greater<long long>());

	vector<tuple<int, int, int>> r;
	long long m = a[0] + b[0] + c[0];
	r.push_back(make_tuple(0, 0, 0));
	cout << m << endl;
	for(int i = 1; i < K; i++) {
		long long tm = 0;
		int ta, tb, tc;
		for(int x = 0; x <= min(i, X-1); x++) {
			for(int y = 0; y <= min(i - x, Y-1); y++) {
				for(int z = 0; z <= min(i - x - y, Z-1); z++) {
					long long s = a[x] + b[y] + c[z];
					for(auto &rr: r) {
						if(get<0>(rr) == x && get<1>(rr) == y && get<2>(rr) == z) goto next;
					}
					if(s <= m) {
						if(s > tm) {
							tm = s;
							ta = x;
							tb = y, tc = z;
						}
					}
					next:
					;
				}
			}
		}
		cout << tm << endl;
		m = tm;
		r.push_back(make_tuple(ta,tb,tc));
	}
}
