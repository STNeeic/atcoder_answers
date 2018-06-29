#include <iostream>

using namespace std;

bool is_exponential(int a) {
  if(a == 1) return true;
  for(int b = 2; b * b <= a; b++) {
    for(int num = b * b;num <= a; num *= b) {
      if(num == a) {
        //cout << b << "**" << num << endl;
        return true;
      }
    }
  }

  return false;
}

int main(void) {
  int X;
  cin >> X;
  for(int i = X; i > 0; i--) {
    if(is_exponential(i)) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
