#include <iostream>
#include <vector>
#include <utility>

using namespace std;
bool ng[1000][1000] = {};
int next_pos[1000][1000][2];

int rev(int a){
  int out = a / 100;
  if(a / 100) {
    out += ((a % 100) / 10) * 10;
    out += (a % 10) * 100;
  } else if(a / 10) {
    out += a / 10;
    out += (a % 10) * 10;
  } else {
    return a;
  }
  return out;
}

pair<int, int> next_pair(const pair<int, int> & p) {
  int a = p.first,b = p.second;
  if(a < b) a = rev(a);
  else b = rev(b);

  if(a < b) return make_pair(a, b - a);
  else return make_pair(a - b, b);
}

int main() {
  for(int i = 1; i < 1000; i++) {
    for(int j = 1; j < 1000; j++) {
      pair<int, int> n,nn;
      n = make_pair(i, j);
      nn = next_pair(n);
      if(nn.first == 0 || nn.second == 0) ng[i][j] = true;
      next_pos[i][j][0] = nn.first;
      next_pos[i][j][1] = nn.second;
    }
  }

  for(int k = 0; k < 1000; k++) {
    for(int i = 1; i < 1000; i++) {
      for(int j = 1; j < 1000; j++) {
        if(ng[next_pos[i][j][0]][next_pos[i][j][1]] == true) ng[i][j] = true;
      }
    }
  }

  int N, M;
  cin >> N >> M;
  int out = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(ng[i][j] == false) {
        //cout << i << "," << j <<" ";
        //cout << next_pos[i][j][0] << " " << next_pos[i][j][1] << endl;
        out++;
      }
    }
  }
  cout << out << endl;
 }
