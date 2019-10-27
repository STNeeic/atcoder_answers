#include <iostream>
using namespace std;


int main() {
	long long N, M;

	/*
		464
		696
		464
	*/

	//よって裏を向いているカードの数は，(N-2) * (M-2) 枚

	cin >> N >> M;

	if(N * M == 1) {
		cout << 1 << endl;
	} else if(N == 1) {
		cout << max(M - 2, 0LL) << endl;
	} else if(M == 1) {
		cout << max(N - 2, 0LL) << endl;
	} else {
		cout << max((M - 2) * (N - 2), 0LL) << endl;
	}
}
