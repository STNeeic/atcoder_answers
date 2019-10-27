#include <iostream>
#include <vector>


using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &x: A) cin >> x;

	int a = -1, b = -1, c = -1;
	int an = 0, bn = 0, cn= 0;

	for(auto x: A) {
		if(x != a && x != b && x != c) {
			if(a == -1) a = x, an++;
			else if(b == -1) b = x, bn++;
			else if(x == (a ^ b)) c = x, cn++;
			else {
				cout << "No" << endl;
				return 0;
			}
		} else {
			if(x == a) an++;
			if(x == b) bn++;
			if(x == c) cn++;
		}
	}

	if((an == bn && bn == cn) || (c == -1 && (((a ^ a) == b && an == 2 * bn) ||((b ^ b) == a && 2 * an == bn))))
		cout << "Yes" << endl;
	else if(a == 0 && b == -1 && c == -1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
