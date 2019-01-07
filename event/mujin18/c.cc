#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<vector< char> > m = vector<vector <char> >(N, vector<char>(M));
  vector<vector< vector<int> > > f = vector<vector<vector<int> > >(N, vector<vector<int> >(M, vector<int>(4)));
  for(auto& row: m)
    for(auto& c: row) cin >> c;

  long long sum = 0;
  for(int i = 0; i < N; i++) {

    for(int j = 0; j < M; j++) {
      if(m[i][j] == '#') {
        continue;
      }
      for(int h = 0; h < 4; h++) {
        int c = 0;
        switch(h) {
        case 0: //left
          if(j - 1 > 0 && m[i][j - 1] == '.') {
            c = f[i][j-1][h] + 1;
            break;
          }
          while(j - c > 0 && m[i][j - c - 1] == '.') c++;
          break;
        case 1: //bottom
          if(i - 1 > 0 && m[i - 1][j] == '.') {
            c = f[i-1][j][h] - 1;
            break;
          }
          while(i + c + 1< N && m[i + c + 1][j] == '.') c++;
          break;
        case 3: //top
          if(i - 1 > 0 && m[i - 1][j] == '.') {
            c = f[i-1][j][h] + 1;
            break;
          }
          while(i - c > 0 && m[i - c - 1][j] == '.') c++;
          break;
        case 2: //right
          if(j - 1 > 0 && m[i][j - 1] == '.') {
            c = f[i][j-1][h] - 1;
            break;
          }
          while(j + c + 1< M && m[i][j + c + 1] == '.') c++;
          break;
        }
        f[i][j][h] = c;
      }
      //cout << "(" << i << "," << j << ") ";
      for(int h = 0; h < 4; h++) {
        //cout << f[i][j][h] << " ";
        sum += f[i][j][h] * f[i][j][(h + 1) % 4];
      }
      //cout << endl;
    }
  }

  cout << sum << endl;
}
