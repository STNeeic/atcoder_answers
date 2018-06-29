#include <iostream>
#include <deque>
#include <utility>
#include <tuple>
#include <vector>

int main() {
  using namespace std;

  int H, W;
  cin >> H >> W;

  auto m = vector< vector< pair<int, char> > >(H, vector< pair<int, char> >(W));
  //最高スコアは (白の数) - (通過するマス目の数)
  int cnt_white = 0;
  for(auto &row: m)
    for(auto &cell: row) {
      char c;
      cin >> c;
      if(c == '.') cnt_white++;
      cell = make_pair(-1, c);
    }

  m[0][0].first = 1;
  auto g = make_pair(H - 1, W - 1);

  deque< pair<int, int> > q;
  q.push_back(make_pair(0,0));

  while(!q.empty()) {
    auto pos = q.front();
    q.pop_front();
    int len;
    char c;
    tie(len, c) = m[pos.first][pos.second];
    if(pos == g) {
      //goal!!
      cout << cnt_white - len << endl;
      return 0;
    }

    if(c == '#') continue;
    for(int i = 0; i < 4; i++) {
      pair<int, int> n;
      if(i < 2) {
        n = make_pair(2 * i - 1 + pos.first, pos.second);
      } else {
        n = make_pair(pos.first, 2 * i - 5 + pos.second);
      }
      int x, y;
      tie(x, y) = n;
      if(x < 0 || x >= H || y < 0 || y >= W) continue;
      auto& l = m[n.first][n.second].first;
      if(l >= 0) continue;

      l = len + 1;
      q.push_back(n);
    }
  }

  cout << "-1" << endl;
}
