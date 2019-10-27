#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void heisei() {
	cout << "Heisei" << endl;
}

void TBD() {
	cout << "TBD" << endl;
}

int main() {
	string t, s;
	cin >> t;
	stringstream ss;
	ss << t;
	int y, m, d;
	getline(ss,s,'/');
	y = stoi(s);
	getline(ss,s,'/');
	m = stoi(s);
	getline(ss,s,'/');
	d = stoi(s);

	if(y < 2019) {
		heisei();
	} else if(y == 2019) {
		if(m < 4) {
			heisei();
		} else if(m == 4) {
			if(d <= 30) {
				heisei();
			} else {
				TBD();
			}
		} else {
			TBD();
		}
	} else {
		TBD();
	}
}
