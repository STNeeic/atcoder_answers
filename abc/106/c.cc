#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ones = 0;
  int num = 1;
  bool f = false;
  for(char s: S) {
    if(!f) {
      if(s == '1') ones++;
      else {
        num = s - '0';
        f = true;
      }
    }
  }

  int k;
  cin >> k;
  if(k <= ones) cout << 1 << endl;
  else cout << num << endl;
}
