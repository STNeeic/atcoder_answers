#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
struct D {
	int x;
	int y;
	ll h;
};
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<D> d(N + 1);

	for(int i = 0; i < N; i++) {
		cin >> d[i].x >> d[i].y >> d[i].h;
		if(d[i].h > 0) {
			d[N] = d[i];
		}
	}

	for(int x = 0; x <= 100; x++) {
		for(int y = 0; y <= 100; y++) {
			ll H = d[N].h + abs(x - d[N].x) + abs(y - d[N].y);
			for(int i = 0; i < N; i++) {
				ll h = max(H - abs(x - d[i].x) - abs(y - d[i].y), 0LL);
				if(h != d[i].h) goto next;
			}
			//passed all. it's vertex!
			cout << x <<" " << y << " " <<  H << endl;
			return 0;
			next:
			;
		}
	}

	return 1;
}
