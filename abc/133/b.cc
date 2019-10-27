#include <iostream>
#include <vector>
using namespace std;
#include <cmath>
int main() {
	int N;
	int D;
	cin >> N >> D;
	vector<vector<int> > X(N, vector<int>(D));
	for(auto& r: X)
		for(auto& c: r)
			cin >> c;

	int out = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			int s = 0;
			for(int k = 0; k < D; k++) {
				s += pow(X[i][k] - X[j][k], 2);
			}
			double r = sqrt(s);
			if(ceil(r) == floor(r)) out++;
		}
	}

	cout << out << endl;
}
