#include <string>
#include <iostream>
#include <bitset>
using namespace std;


int main() {
	string s, t;
	cin >> s >> t;

	bitset<'z' - 'a' + 1> cs;
	for(char i = 'a'; i <= 'z'; i++) {
		char c = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == i) {
				if(c == 0) {
					c = t[j];
					if(cs[c - 'a']) {
						cout << "No" << endl;
						return 0;
					}
					cs[c - 'a'] = true;
				} else {
					if(t[j] != c) {
						cout << "No" << endl;
						return 0;
					}
				}
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}
