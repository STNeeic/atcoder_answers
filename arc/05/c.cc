#include <iostream>

#include <vector>
#include <tuple>
#include <utility>
#include <deque>
#include <bitset>



int main() {
  using namespace std;
  int H, W;
  cin >> H >> W;
  auto m = vector< vector< pair<bool, char> > >(H, vector< pair<bool, char> >(W));

  using p_t = pair<int, int>;
  p_t s, g;
  for(int x = 0; x < H; x++) {
    for(int y = 0; y < W; y++) {
      char cell;
      cin >> cell;
      m[x][y] = make_pair(false, cell);
      if(cell == 's') {
        s = make_pair(x, y);
      } else if(cell == 'g') {
        g = make_pair(x, y);
      }
    }
  }
  deque<pair<int, p_t> > q;

  q.push_back(make_pair(0 , s));

  while(!q.empty()) {
    int nm;
    p_t n;
    tie(nm, n) = q.front();

    q.pop_front();
    auto & cc = m[n.first][n.second];
    char c = cc.second;
    cc.first = true;
    if(c == 'g') {
      cout << "YES" << endl;
      return 0;
    }
    if(c == '#') {
      if(nm >= 2) continue;
      nm++;
    }

    for(int i = 0; i < 4; i++) {
      p_t nn = n;
      if(i < 2) {
        nn.first += 2 * i - 1;
      } else {
        nn.second += 2 * i - 5;
      }
      int x, y;
      tie(x, y) = nn;
      if(x < 0 || x >= H || y < 0 || y >= W || m[nn.first][nn.second].first) continue;
      if(c == '#')
        q.push_back(make_pair(nm, nn));
      else
        q.push_front(make_pair(nm, nn));
    }
  }

  cout << "NO" << endl;
}
