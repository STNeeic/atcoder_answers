#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

bitset<100> digit;



void get_digit(long long n) {
  vector<long long> o;
  vector<long long> e;
  long long j = 1;
  for(int k = 0; k < 100; k++, j *= -2) {
    if(j > 0) {
      //o
      o.push_back(o.size() > 0 ? j + o[o.size() - 1] : j);
    } else {
      //e
      e.push_back(e.size() > 0 ? j + e[e.size() - 1] : j);
    }
  }
  for(int i = 0; ; i++) {
    if(n == 0) return;
    if(i % 2 == 0 ) {
      if(n > 0 && n <= o[i/2]) {
        cout << n << endl;
        n -= i > 0 ? o[i/2] - o[i/2-1] : 1;
        digit.set(i);
        i = -1;
      }
    } else {
      if (n < 0 && e[(i - 1)/2] <= n) {
        digit.set(i);
        cout << n << endl;
        n -= i > 1 ? e[(i - 1)/2] - e[(i - 1)/2-1] : -2;
        i = -1;
      }
    }
  }
}

void print_digit() {
  int l = 0;
  for(int i = 0; i < 1000; i++) {
    l = digit[i] ? i : l;
  }

  for(int i = l; i >= 0; i--) {
    cout << (digit[i] ? "1" : "0");
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  get_digit(n);
  print_digit();
}
