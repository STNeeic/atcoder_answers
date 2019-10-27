#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> B(N - 1);
	for(auto &x: B) cin >> x;

	//先頭
	int sum = B[0];
	for(int i = 1; i < N - 1; i++) {
		sum += min(B[i - 1], B[i]);
	}
	//末尾
	sum += B[N - 2];
	cout << sum << endl;
}
