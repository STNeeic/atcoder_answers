#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
	int L, R;
	cin >> L >> R;

	bitset<2019> r;

	for(int i = L; i <= R; i++) {
		r[i % 2019] = true;
		if(r.all() == true) break;
	}

	int m = 2018;

	for(int i = 0; i < 2019; i++) {
		for(int j = i + 1; j < 2019; j++) {
			if(r[i] == false || r[j] == false) continue;
			int t = i * j;
			t %= 2019;
			m = min(m, t);
		}
	}

	cout << m << endl;
}
