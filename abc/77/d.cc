#include <iostream>

int sum(int a) {
  int res = 0;
  while(a  > 0) {
    res += a % 10;
    a /= 10;
  }
  return res;
}

int next(int i) {
  int n = i++;
  while(n % 2 == 0 || n % 5 == 0) n++;
  return n;
}

int main(void) {
  int a;
  std::cin >> a;
  int min = sum(a);
  for(int i = 2; i < 50000000; i = next(i)) {
    int b = sum(a * i);
    min = min < b ? min : b;
  }
  std::cout << min << std::endl;
  return 0;
}
