#include <iostream>

using namespace std;


int main() {
	int N;
	cin >> N;
	int max = 0, out = 0;
	for(int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if(n >= max) max = n, out++;
	}

	cout << out << endl;
}
