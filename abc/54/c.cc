#include <iostream>
#include <vector>
#include <bitset>
#include <utility>

bool path[8][8] = {};

using namespace std;


int search(bitset<8> state, int position, int N) {
  state.set(position);

  bitset<8> s = state | bitset<8>(((1 << 8) - 1) ^ ((1 << N) - 1));
  if(s.all()) return 1;

  int num = 0;
  for(int i = 0; i < N; i++) {
    if(i == position) continue;
    if(path[position][i] != true) continue;
    if(state[i] == true) continue;
    num += search(state, i, N);
  }

  return num;

}

int main() {
  int N, M;
  cin >> N >> M;

  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    path[a][b] = true;
    path[b][a] = true;
  }

  cout << search(bitset<8>(), 0, N) << endl;
}
