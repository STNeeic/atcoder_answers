#include <iostream>
#include <string>
#include <vector>
long get_lucas_num(int i) {
  std::vector<long> luca(i);
  long luca0 = 2;
  long luca1 = 1;
  long luca2 = luca0 + luca1;
  for(int j = 2; j <= i; j++) {
    luca0 = luca1;
    luca1 = luca2;
    luca2 = luca0 + luca2;
  }
  return luca1;
}

int main(void) {
  int a;
  std::cin >> a;
  long out = get_lucas_num(a);

  std::cout << out << std::endl;
  return 0;
}
