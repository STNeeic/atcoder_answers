#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int l = 0, m = 0;
	for(auto &x: s) {
		if(x == 'A' || x == 'T' || x == 'G' || x == 'C') {
			l++;
			m = max(l, m);
		} else {
			l = 0;
		}
	}

	cout << m << endl;
}
