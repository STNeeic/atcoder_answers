#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  vector<int> num(s.length());

  for(int i = 0; i < s.length(); i++) {
    num[i] = s[i] - '0';
  }

  int spaces = s.length() - 1;
  long bits = 1 << spaces;

  long long sum = 0;
  for(long i = 0; i < bits; i++) {
    int hoge = num[0];
    for(long d = 0; d < spaces; d++) {
        if(i & (1 << d)) {
          cout << i << " " << hoge << endl;
          sum += hoge;
          hoge = 0;
        }
        hoge *= 10;
        hoge += num[d + 1];
    }
    sum += hoge;
  }

  cout << sum << endl;
  return 0;
}
