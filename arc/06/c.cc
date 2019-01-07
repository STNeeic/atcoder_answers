#include <iostream>
#include <vector>

int main() {
  using namespace std;
  int N;
  vector<int> tops;
  cin >> N;
  for(int i = 0 ; i < N ; i++) {
    int n;
    cin >> n;
    bool flag = false;
    for(auto& x:tops) {
      if(x >= n) {
        x = n;
        flag = true;
        break;
      }
    }
    if(flag == false) {
      tops.push_back(n);
    }
  }

  cout << tops.size() << endl;
}
