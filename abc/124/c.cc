#include <iostream>
#include <string>

using namespace std;


int main() {
	string S;
	cin >> S;

	//0101,,, or 1010...
	int l = 0, r = 0;
	for(int i = 0; i < S.size(); i++) {
		if(i % 2 == 0) {
			if(S[i] == '0') r++;
			else l++;
		} else {
			if(S[i] == '0') l++;
			else r++;
		}

	}

	cout << min(l, r) << endl;
}
