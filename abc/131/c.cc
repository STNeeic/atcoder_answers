#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	if(a < b) gcd(b, a);
	if(b == 0) return a;
	long long r = a % b;
	return gcd(b, r);
}

int main() {
	long long A, B, C, D;
	cin >> A >> B >> C >> D;
	A--;
	long long ca, cb, da, db, cda, cdb;
	ca = A / C, cb = B / C, da = A / D, db = B / D;
	long long CD = C * D / gcd(C, D);
	cda = A / CD, cdb = B / CD;
//	cout << ca << " " << cb << " " << da << " " << db << " " << cda << " " << cdb << endl;
	cout << B - A - (cb - ca) - (db - da) + (cdb - cda) << endl;

}
