#include <iostream>
#include <vector>

int main(void) {
  std::vector<char> v1, v2;
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 3; i++) {
      char input;
      if(std::cin >> input) {
        if(j == 0)
          v1.push_back(input);
        else
          v2.push_back(input);
      }
    }
  }

  /*for(char c : v1) {
    std::cout << c << std::endl;
  }
  for(char c : v2) {
    std::cout << c << std::endl;
  }
  */

  if(v1[0] == v2[2] and v1[1] == v2[1] and v1[2] == v2[0])
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
  return 0;
}
