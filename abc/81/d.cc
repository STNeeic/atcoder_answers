#include <iostream>
#include <vector>

struct pair {
  int index;
  int value;
};

int main(int argc, char**argv) {
  int n;
  std::cin >> n;
  std::vector<int> a(n);

  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  pair max = {0, a[0]};
  pair min = {0, a[0]};

  for(int i = 0; i < n; i++) {
    if(a[i] < min.value) {
      min.index = i;
      min.value = a[i];
    } else if (max.value < a[i]) {
      max.index = i;
      max.value = a[i];
    }
  }

  /*
   * a[i] += min.value (or max.value)
   * a[i] = sum(a, 0..i) + i * max.value(or (n-i) * min.value)
   */
  std::cout << 2 * n - 2 << std::endl;

  if(min.value * -1 > max.value) {
    for(int i = 0; i < n; i++) {
      if(min.index != i) {
        std::cout << min.index + 1<< " " << i + 1<< std::endl;
      }
    }
    for(int i = n - 1; i > 0; i--) {
      std::cout << i+ 1 << " " << i << std::endl;
    }
  } else {
    for(int i = 0; i < n; i++) {
      if(max.index != i) {
        std::cout << max.index + 1<< " " << i + 1<< std::endl;
      }
    }
    for(int i = 1; i < n; i++) {
      std::cout << i<< " " << i + 1<< std::endl;
    }
  }
  return 0;
}
