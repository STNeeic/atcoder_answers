#include <iostream>
#include <string>
using namespace std;


string M = "MARCH";
int main() {
	int N;
	long long cnt[5] = {};
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < 5; j++) {
			if(s[0] == M[j]) {
				cnt[j]++;
				break;
			}
		}
	}

	long long res = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = i + 1; j < 4; j++) {
			for(int k = j + 1; k < 5; k++) {
				res += cnt[i] * cnt[j] * cnt[k];
			}
		}
	}
	cout << res << endl;
}
