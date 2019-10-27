#include <iostream>

using namespace std;


int main() {

	int A, B;
	cin >> A >> B;
	int out;
	if(A > B) out = A, A--;
	else out = B, B--;
	if(A > B) out += A;
	else out += B;

	cout << out << endl;

}
