#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
	string S;
	int K;
	cin >> S >> K;

	priority_queue<string, vector<string>, greater<string>> q;
	unordered_map<string, bool> m;
	for(int i = 0; i < S.size(); i++) {
		for(int l = 1; l <= K && i + l <= S.size(); l++) {
			string s(S, i, l);
			if(m.find(s) == m.end()) {
				m.emplace(s, true);
				q.push(s);
			}
		}
	}

	for(int i = 0; i < K - 1; i++) q.pop();
	cout << q.top() << endl;
}
