#include <iostream>
#include <vector>

int get_two(int b) {
  auto out = 0;
  while(b % 2 == 0 && b > 0) {
    out++;
    b /= 2;
  }
  return out;
}

int main(void){
  int num;
  std::cin >> num;
  std::vector<int> a(num);
  for(int i = 0; i < num; i++){
    int tmp;
    std::cin >> tmp;
    a[i] = tmp;
  }
  int min = 114514;
  for(auto x : a) min = std::min(min, get_two(x));
  std::cout << min << std::endl;
  return 0;
}
