#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> p;
	for(int i = 0; i < N; i++) {
		int A;
		cin >> A;
		A = INT_MAX - A;
		auto it = upper_bound(p.begin(), p.end(), A);
		if(it == p.end()) {
			p.push_back(A);
		} else {
			*it = A;
		}
	}

	cout << p.size() << endl;
}
