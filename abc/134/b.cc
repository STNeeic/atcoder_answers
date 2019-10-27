#include <iostream>

using namespace std;

int main() {
	int N , D;
	cin >> N >> D;
	int r = N / (2 * D + 1);
	if(N % (2 * D + 1) != 0) r++;
	cout << r << endl;
}
