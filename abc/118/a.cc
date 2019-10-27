#include <iostream>

using namespace std;

int main() {
	int A , B;
	cin >> A >> B;

	int out = (B % A == 0) ? (A + B) : (B - A);
	cout << out << endl;
}
