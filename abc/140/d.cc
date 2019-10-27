#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	int gap = 0;
	char prev = S[0];
	for(int i = 1; i < S.size(); i++) {
		if(S[i] != prev) gap++;
		prev = S[i];
	}
	cout << N - 1 - max(0, gap - 2 * K) << endl;
}
