#include <iostream>

using namespace std;

int main() {
	char a;
	cin >> a;
	char b;
	switch(a) {
		case 'A':
			b = 'T';
			break;
		case 'T':
			b = 'A';
			break;
		case 'G':
			b = 'C';
			break;
		case 'C':
			b = 'G';
			break;
	}
	cout << b << endl;

}
