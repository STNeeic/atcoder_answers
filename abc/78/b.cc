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
  int X,Y, Z;
  std::cin >> X >> Y >> Z;
  std::cout << (X - Z)/(Y + Z) << std::endl;
  return 0;
}
