#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	int N , K;
	cin >> N >> K;
	int m = N / K;
	int t = (N + K/2) / K;

	long long res = 0;
		res = pow(m, 3);
	if(K % 2 == 0) res += pow(t, 3);
	cout << res << endl;
}
