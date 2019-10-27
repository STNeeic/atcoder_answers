#include <iostream>
#include <vector>
#include <string>

using namespace std;
int calch(int x, int y, const vector<vector<char> > &s) {
	int res = 0;
	int b = x, f = x;
	if(s[x][y] == '#') return -1;
	while(b >= 0 && s[b][y] == '.') b--, res++;
	while(f < s.size() && s[f][y] == '.') f++, res++;
	res--;
	return res;
}
int calcw(int x, int y, const vector<vector<char> > &s) {
	int res = 0;
	int b = y, f = y;
	if(s[x][y] == '#') return -1;
	while(b >= 0 && s[x][b] == '.') b--, res++;
	while(f < s[x].size() && s[x][f] == '.') f++, res++;
	res--;
	return res;
}
int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char> > s(H, vector<char>(W));

	for(auto &r: s)
		for(auto &x: r) cin >> x;

	int bh[W];
	for(int i = 0; i < W; i++) bh[i] = -1;
	int bw = -1;
	int res = 0;
	for(int i = 0; i < H; i++) {
		bw = -1;
		for(int j = 0; j < W; j++) {
			if(s[i][j] == '#') {
				bw = -1;
				bh[j] = -1;
				continue;
			}
			if(bw == -1) bw = calcw(i, j, s);
			if(bh[j] == -1) bh[j] = calch(i, j, s);
			//cout << "(" << i << "," << j << ")=" << bw + bh[j] -1 << endl;
			res = max(res, bw + bh[j] - 1);
		}
	}

	cout << res << endl;
}
