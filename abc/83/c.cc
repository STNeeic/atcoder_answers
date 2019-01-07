#include <iostream>

using namespace std;

int main() {
  unsigned long long X, Y;
  cin >> X >> Y;
  int res = 0;
  for(auto i = X; i <= Y; i *= 2) {
    res++;
  }
  cout << res << endl;
}
