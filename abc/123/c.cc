#include <iostream>
#include <vector>
using namespace std;


int main() {

	unsigned long long N;
	vector<unsigned long long> a(5);
	cin >> N;
	for(auto &x: a) cin >> x;
	sort(a.begin(), a.end());
	unsigned long long b = a[0];
	unsigned long long out = (N - 1) / b + 5;
	cout << out << endl;
}
