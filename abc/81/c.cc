#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n, 0);
  for(auto x : a) {
    int tmp;
    std::cin >> tmp;
    a[tmp - 1]++;
  }
  std::sort(a.begin(),a.end());
  int out = 0;
  for(int i = 0; i < n - k; i++) {
    out += a[i];
  }
  std::cout << out << std::endl;

}
