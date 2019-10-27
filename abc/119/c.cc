#include <iostream>
#include <vector>

using namespace std;

bool is_fair(vector<int> &s) {
	bool one = false, two = false, three = false;
	for(auto &&x: s) {
		if(x == 1) one = true;
		if(x == 2) two = true;
		if(x == 3) three = true;
	}
	return one && two && three;
}

bool is_zero(vector<int> &s) {
	bool y = true;
	for(auto &&x: s) {
		if(x != 0) y = false;
	}
	return y;
}

int calc_cost(int A, int B, int C, vector<int> &s, vector<int> &v) {
	int aa = 0, bb = 0, cc = 0;
	int ac = 0, bc = 0, cs = 0;

	for(int i = 0; i < s.size(); i++) {
		switch(s[i]) {
		case 1:
			if(aa > 0) ac += 10;
			aa += v[i];
			break;
		case 2:
			if(bb > 0) bc += 10;
			bb += v[i];
			break;
		case 3:
			if(cc > 0) cs += 10;
			cc += v[i];
			break;
		}
	}
	ac += abs(A - aa);
	bc += abs(B - bb);
	cs += abs(C - cc);
	return ac + bc + cs;
}


int main() {
	int N, A, B, C;
	cin >> N >> A >> B >> C;

	vector<int> v(N);

	for(auto &x: v) cin >> x;

	vector<int> s(N, 0);

	int min_cost = 1145141919;
	s[0] = 1;
	while(is_zero(s) == false) {
	if(is_fair(s)) {
		min_cost = min(min_cost, calc_cost(A, B, C, s, v));
	}

	s[0] += 1;
	for(int i = 0; i < N; i++) {
		if(s[i] == 4) {
			s[i] = 0;
			if(i + 1 < N)
				s[i + 1] += 1;
		}
	}
	}

	cout << min_cost << endl;
}
