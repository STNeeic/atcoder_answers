#include <iostream>

using namespace std;

int main() {
	int N;
	int a = -1,an = -1, b = -1;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int r;
		cin >> r;
		if(r > a) b = a, a = r, an = i;
		else if(r > b) b = r;
	}

	for(int i = 0; i < N; i++) {
		if(i == an) cout << b << endl;
		else cout << a << endl;
	}
}
