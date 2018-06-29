#include <iostream>
using namespace std;
int main(void) {
  int N,A,B;
  cin >> N >> A >> B;
  cout << (N*A > B ? B : N*A) << endl;
  return 0;
}
