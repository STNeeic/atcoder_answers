#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {

  int n;
  std::cin >> n;
  std::vector<int> a, b, c;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n; j++) {
      int tmp;
      std::cin >> tmp;
      switch(i) {
      case 0:
        a.push_back(tmp);
        break;
      case 1:
        b.push_back(tmp);
        break;
      case 2:
        c.push_back(tmp);
        break;
      }
    }
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end(), std::greater<int>());
  std::sort(c.begin(), c.end(), std::greater<int>());

  std::vector<int> b_num;
  int prev_num = 0;
  for(int j = 0; j < n; j++) {
    int num = prev_num;
    for(int k = prev_num; k < n; k++) {
      if(b[j] < c[k]) num++;
      else
        break;
    }
    b_num.push_back(num);
    prev_num = num;
  }
  int sum = 0;
  prev_num = 0;
  int prev_jsum = 0;
  for(int i = 0; i < n; i++) {
    int jsum = prev_jsum;
      for(int j = prev_num; j < n; j++) {
        if(a[i] >= b[j]){
          prev_num = j;
          break;
        }
        jsum += b_num[j];
    }
      sum += jsum;
      prev_jsum = jsum;
  }

  std::cout << sum << std::endl;
  return 0;
}
