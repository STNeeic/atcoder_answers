#include <iostream>
#include <complex>

int main(void) {
  // x = a, y = b の順位をとったとして、
  // 得点が下回る人数は、 k = abなるkをとり、 k > xy となる整数xyの総数
  using namespace std;
  int Q;
  cin >> Q;
  for(int i = 0; i < Q; i++) {
    unsigned long long a, b;
    cin >> a >> b;
    unsigned long long k = a * b;
    unsigned long long k_rt = (unsigned long long) sqrt(k);
    int same = 1;
    if(k_rt * (k_rt + 1) >= k) same = 2;
    if(k_rt * k_rt == k && (k_rt != a && k_rt != b)) same = 3;
    cout << 2 * k_rt - same << endl;
  }
  return 0;
}
