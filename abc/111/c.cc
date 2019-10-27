#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	int n;
	cin >> n;

	vector<int> a(100001, 0), b(100001, 0);

	for(int i = 0; i < n / 2; i++) {
		int c, d;
		cin >> c >> d;
		a[c]++;
		b[d]++;
	}

	priority_queue<pair<int, int>> qa, qb;

	for(int i = 1; i <= 100000; i++) {
		qa.push(make_pair(a[i], i));
		qb.push(make_pair(b[i], i));
	}

	auto aa = qa.top(), bb = qb.top();

	if(aa.second == bb.second) {
		qa.pop();
		qb.pop();
		auto aa2 = qa.empty() ? make_pair(0, 0) : qa.top();
		auto bb2 = qb.empty() ? make_pair(0, 0) : qb.top();
		if(aa2.first + bb.first > aa.first + bb2.first) aa = aa2;
		else bb = bb2;
	}

	cout << n - aa.first - bb.first << endl;
}
