#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	if(K > 1) cout << N - K << endl;
	else cout << 0 << endl;
}
