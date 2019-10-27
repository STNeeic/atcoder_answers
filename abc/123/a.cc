#include <iostream>
#include <string>
#include <vector>
using namespace std;


string y = ":(";
string n = "Yay!";

bool ok(vector<int> v, int k) {
	if(v[4] - v[0] > k) return true;
	return false;
}
int main() {

	vector<int> a(5);
	for(auto &x: a) cin >> x;
	int k;
	cin >> k;
	if(ok(a, k)) cout << y << endl;
	else cout << n << endl;
}
