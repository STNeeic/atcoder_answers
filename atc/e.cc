#include <iostream>
#include <string>

using namespace std;

string N;
int D;
const int mod = 1000000007;
int rec(int k = 0, bool tight = true, int sum = 0) {
  int x = N[k] - '0';
  int r = tight ? x : 9;

}
int main() {

  cin >> D >> N;
  cout << rec() << endl;
}
