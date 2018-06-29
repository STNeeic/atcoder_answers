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
  int N, M;
  std::cin >> N >> M;
  int r = 1;
  for(int i = 0; i < M; i++) {
    r *= 2;
  }
  std::cout << (1900 * M + 100 * (N - M)) * r << std::endl;
  return 0;
}
