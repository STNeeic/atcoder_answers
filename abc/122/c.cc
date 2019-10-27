#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

	int N, Q;
	cin >> N >> Q;

	string s;
	cin >> s;
	vector<int> a(N, 0);

	for(int i = 1; i < N; i++) {
		if(s[i-1] == 'A' && s[i] == 'C') {
			a[i] = a[i-1] + 1;
		} else {
			a[i] = a[i-1];
		}
	}

	for(int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;
		cout << a[r-1] - a[l-1] << endl;
	}
}
