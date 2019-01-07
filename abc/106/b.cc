#include <iostream>
#include <vector>
using namespace std;


int main() {
  vector<int> num;
  for(int i = 1; i <= 200; i += 2) {
    int y = 0;
    for(int j = 1; j <= i; j++) {
      if(i % j == 0) y++;
    }
    if(y == 8) num.push_back(i);
  }

  int n;
  cin >> n;
  int out = 0;
  for(auto x: num) {
    if(x <= n) out++;
  }

  cout << out << endl;
}
