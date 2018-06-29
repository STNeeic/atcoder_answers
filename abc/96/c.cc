#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  char s[H][W];
  for(auto& x : s) {
    for(auto& cell : x) {
      cin >> cell;
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(s[i][j] == '#') {
        if(i > 0 && s[i-1][j] == '#') continue;
        if(j > 0 && s[i][j-1] == '#') continue;
        if(i < H-1 && s[i+1][j] == '#') continue;
        if(j < W-1 && s[i][j+1] == '#') continue;
        //can't draw
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
