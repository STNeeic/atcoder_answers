#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(const vector<int> &a) {
	int out = 0;
	for(auto &x: a) {
		out += out % 10 != 0 ? 10 - (out % 10) : 0;
		out += x;
	}
	return out;
}
int main() {

	vector<int> a(5);
	for(auto &x: a) cin >> x;

	sort(a.begin(), a.end());
	int out = 114514;
	for(bool f = true; f; f = next_permutation(a.begin(), a.end())) {
		out = min(out, calc(a));
	}

	cout << out << endl;
}
