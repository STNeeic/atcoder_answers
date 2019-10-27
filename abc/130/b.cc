#include <iostream>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	int n = 0, cnt = 1;
	for(int i = 0; i < N; i++) {
		int L;
		cin >> L;
		n += L;
		if(n <= X) cnt++;
	}
	cout << cnt << endl;
}
