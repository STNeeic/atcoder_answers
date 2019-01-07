#include <iostream>
#include <bitset>

using namespace std;
int main() {
  bitset<101> ok;

  for(int f = 0; f <= 100 / 4 ; f++) {
    for(int s = 0; s <= 100 / 7; s++) {
      if(4 * f + s * 7 > 100) continue;
      ok.set(4 * f + s * 7);
    }
  }

  int n;
  cin >> n;
  cout << (ok[n] ? "Yes" : "No") << endl;
}
