#include <iostream>
#include <string>

bool is_good_num(int a) {
  int b = a % 10;
  a /= 10;
  int c = a % 10;
  a /= 10;
  int d = a % 10;
  a /= 10;
  int e = a % 10;
  return (c == d and (d == e || b == c));
}

int main(void) {
  int a;
  std::cin >> a;
  std::string out = "No";
  if(is_good_num(a)) {
    out = "Yes";
  }

  std::cout << out << std::endl;
  return 0;
}
