#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


const double c = 380000;

int main() {
	int N;
	cin >> N;

	double out = 0;
	for(int i = 0; i < N; i++) {
		string s;
		double y;
		cin >> y >> s;
		if(s.compare("JPY") == 0) {
			out += y;
		} else {
			out += y * c;
		}

	}

	cout << out << endl;
}
