#include <iostream>

using namespace std;

int main (void) {
  int A,B,K;
  cin >> A >> B >> K;
  for(int i = A; i <= B; i++) {
    if(i - K < A || i + K > B) {
      cout << i << endl;
    }
  }
  return 0;
}
