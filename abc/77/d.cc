#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Node {
	struct Node * plus;
	struct Node * mul;
	int num;
};
int main() {
	int K;
	cin >> K;
	vector<struct Node> N(K);
	for(int i = 0; i < K; i++) {
		N[i].num = i;
		N[i].plus = &N[(i + 1) % K];
		N[i].mul = &N[(i * 10) % K];
	}

	vector<int> C(K, INT_MAX);
	deque<pair<int , int>> d;
	d.push_back(make_pair(1, 0));
	while(true) {
		auto x = d.front();
		if(x.first == 0) {
			cout << x.second + 1 << endl;
			return 0;
		}
		d.pop_front();
		if(C[x.first] <= x.second) continue;
		C[x.first] = x.second;
		d.push_back(make_pair(N[x.first].plus->num, x.second + 1));
		d.push_front(make_pair(N[x.first].mul->num, x.second));
	}
}
