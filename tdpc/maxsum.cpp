#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> s(N, 0);

	for(auto&x :a) {
		cin >> x;
	}

	for(int i = 0; i < s.size(); i++) {
		if(a[i] > 0) {
			if(i == 0) s[i] = a[i];
			else s[i] = s[i - 1] + a[i];
		} else if(i > 0) {
			s[i] = s[i - 1];
		}
	}

	cout << s[s.size() - 1] << endl;
}
