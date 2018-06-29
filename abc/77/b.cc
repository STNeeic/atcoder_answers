#include <iostream>

int main(void) {
  int limit = 1;
  int max_square = 1;
  std::cin >> limit;
  for(int i = 1; i*i <= limit; i++) {
    max_square = i * i;
  }
  std::cout << max_square << std::endl;
  return 0;
}
