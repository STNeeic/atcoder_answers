#include <iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int res = 0;
	for(int i = 0; i < N; i++) {
		int t;
		cin >> t;
		res += t - 1;
	}
	cout << res << endl;
}
