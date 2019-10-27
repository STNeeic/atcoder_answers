#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	vector< vector<int> > dp(s.length() + 1, vector<int>(t.length() + 1, 0));

	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < t.length(); j++) {
			int is_same_char = 0;
			if(s[i] == t[j]) is_same_char = 1;
			dp[i+1][j+1] = max({dp[i][j] + is_same_char, dp[i][j+1], dp[i+1][j]});
		}
	}

	string out = "";
	int i = s.length() - 1, j = t.length() - 1;
	while(i >= 0 && j >= 0) {
		int n = 0;
		if(dp[i][j] < dp[i+1][j]) n = 1;
		else if(dp[i][j] < dp[i][j+1]) n = 2;
		else if(dp[i][j] == dp[i+1][j+1]) n = 3;

		switch(n) {
			case 0:
			out += s[i];
			case 3:
			i--, j--;
			break;
			case 1:
			j--;
			break;
			case 2:
			i--;
			break;
		}
	}

	reverse(out.begin(), out.end());
	cout << out << endl;
}
