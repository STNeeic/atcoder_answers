#include <iostream>
#include <string>
int main(void) {
  using namespace std;
  string s = "abc";
  string inp;
  cin >> inp;
  for(auto c : s) {
    for(auto d : inp) {
      if(c == d) goto next;
    }
    // if inp does not have c
    cout << "No" << endl;
    return 0;
  next:
    ;
  }
  cout << "Yes" << endl;
  return 0;
}
