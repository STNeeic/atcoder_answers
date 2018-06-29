#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int main(){
  int H, W;

  cin >> H >> W;
  vector< vector<char> > m = vector< vector<char> >(H, vector<char>(W));

  pair<int, int> start;

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> m[i][j];
      if(m[i][j] == 's') {
        start.first = i;
        start.second = j;
      }
    }
  }

  vector< pair<int, int> > r;
  r.push_back(start);

  while(!r.empty()) {
    pair<int, int> pos = r[r.size() - 1];
    r.pop_back();
    char c = m[pos.first][pos.second];
    if(c == 'g') {
      cout << "Yes" << endl;
      return 0;
    } else if(c == '#') {
      continue;
    } else if(c == '.' || c == 's') {
      m[pos.first][pos.second] = '#';
      for(int dx = -1; dx < 2; dx += 2) {
        int x = pos.first + dx;
        int y = pos.second;
        if(x < 0 || x >= H || y < 0 || y >= W) continue;
        r.push_back(make_pair(x, y));
      }
      for(int dy = -1; dy < 2; dy += 2) {
        int x = pos.first;
        int y = pos.second + dy;
        if(x < 0 || x >= H || y < 0 || y >= W) continue;
        r.push_back(make_pair(x, y));
      }
    }
  }

  cout << "No" << endl;
}
