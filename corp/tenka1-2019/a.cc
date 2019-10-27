#include <iostream>
#include <vector>

using namespace std;
int main() {
	int A, B, C;


	cin >> A >> B >> C;

	if(C < A) {
		int s;
		s = C;
		C = A;
		A = s;
	}

	if(A < B && B < C) cout << "Yes" << endl;
	else cout << "No" << endl;

}
