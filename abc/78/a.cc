#include <iostream>
#include <vector>
#include <algorithm>

void print_comp(char x, char y) {
  if(x > y) {
    std::cout << ">" << std::endl;
  } else if(x < y) {
    std::cout << "<" << std::endl;
  } else {
    std::cout << "=" << std::endl;
  }
}
int main(void) {
  char X,Y;
  std::cin >> X >> Y;
  print_comp(X,Y);
  return 0;
}
